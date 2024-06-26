import numpy as np
from Buerger_reduction import dist
from matrix_NbyN import put_reduction_matrix_4D

def I_ext ():
    return np.vstack ([np.identity (3, dtype=int), np.array ([-1,-1,-1])])

def S_3x3_to_4x4 (S):
    In = I_ext()
    return In.dot (S).dot(In.T)

def Selling_reduction_3D (S_input):
    """ Selling reduction algorithm for 3D lattices from Conway's book.
    input : 4x4 matrix S = S_input equal to I_ext*S*I_ext^T of a symmetric positive-definite S. 
    output: 4x4 basis transform matrix g and g*S*(g^T)
             such that g S g^T is Selling reduced (i.e., all non-diagonal entries are <= 0). """
    ISIZE = 4
    assert S_input.shape == (ISIZE, ISIZE)
    S = S_input.copy()
    g = np.identity (ISIZE, dtype=int) # Set g = I
    itnum = 0
    while True:
        if any (np.diag (S) <= 0) or itnum > 10000:
            return False, g, S
        itnum = itnum+1
        
        # Search for i, j such that S[i,j] > 0
        flg = False
        for i in range (ISIZE):
            for j in range (i + 1, ISIZE):
                if S[i,j] > 0:
                    flg = True
                    break
            if flg: break
        
        # If non-diagonal entries of S are <= 0, Selling reduction is successful.
        if not flg:
            assert dist(S, g.dot (S_input).dot (g.T)) <= dist(S_input, np.zeros((ISIZE,ISIZE)))*1.0e-10, "Reduced S:\n" + str(S)
            return True, g, S
        
        g2 = put_reduction_matrix_4D (i, j)
        g = g2.dot (g)
        S = g2.dot (S).dot (g2.T)
    
    return False, g, S


def putMatrixToMoveSmallerDiagonalLeftUpper (S):
    ISIZE = len (S)
    tray = np.diag (S) # Take diagonal entries of S
    # Sort in ascending order
    indices = np.argsort (tray)
    g = np.zeros ((ISIZE,ISIZE), dtype=int)
    for k in range (ISIZE):
        g[k, indices[k]] = 1
    return g

def moveSmallerDiagonalLeftUpper (S):
    """ Move smaller diagonal to left upper direction
    input: nxn matrix S
    output: permutation matrix g and g*S*(g^T) such that the entries of g S g^T are in ascending order. """
    g = putMatrixToMoveSmallerDiagonalLeftUpper (S)
    return g, g.dot (S).dot (g.T)


def Delaunay_reduction (S_input):
    """ Delaunay reduction algorithm for 3D lattices.
    input : 3x3 symmetric positive-definite matrix S = S_input. 
    output: 3x3 basis transform matrix g and g*S*(g^T)
             such that S_red = g S g^T = (sij) is Delaunay reduced (i.e., s11<=s22<=s33<=s44
             and all non-diagonal entries of I_ext*S_red*I_ext^T are <= 0). """
    S4 = S_3x3_to_4x4 (S_input)
    flg, g_4x4, S4 = Selling_reduction_3D (S4)
    assert flg # Selling reduction should not be failed.
    g2_4x4, S4 = moveSmallerDiagonalLeftUpper (S4)
    
    # Remove the last column of g_44*I_ext and the last row & column of S4.
    g = np.delete(g2_4x4.dot (g_4x4).dot (I_ext()), 3, 0)
    S = np.delete(np.delete(S4, 3, 0), 3, 1)
    assert dist(S, g.dot (S_input).dot (g.T)) <= dist(S_input, np.zeros((3,3)))*1.0e-10, "Reduced S:\n" + str(S) + "\nReduced g.S_input.g^T:\n" + str(g.dot (S_input).dot (g.T))
    return g, S


def Buerger_to_Selling (S_buer):
    """ Transform Buerger reduced S_buer to a Delaunay reduced symmetric matrix.
    input : Buerger reduced S_del (3x3 symmetric positive-definite matrix)
    output: 3x3 basis transform matrix g and g*S*(g^T)
             such that g S g^T = (sij) is Selling reduced. """
    g = np.identity (3, dtype="int");
    if S_buer[0,2] > 0: # Delaunay reduced otherwise.
        # S_buer[0,1], S_buer[0,2], S_buer[1,2] are positive.
        # S(x,y,z) := S_buer(x,-y,z)
        if S_buer[0,2] <= min(S_buer[0,1], S_buer[1,2]):
            # S(1,1,1) <= S(-1,1,1), S(1,1,-1)
            # -l1, l1-l2, l3, l2 - l3 with the sums -l2, -l1+l3, l1-l2+l3.
            g[0,0] =-1
            g[1,0] = 1
            g[1,1] =-1
        elif S_buer[0,1] < S_buer[1,2]:
            # S[0,1] + S[0,2] > 0 => S(-1,1,1) <= S(1,1,1), S(1,1,-1)
            # l1, -l2, -l1+l3, l2-l3 with the sums l1-l2, l3, -l1-l2+l3.
            g[1,1] =-1
            g[2,0] =-1
        else: 
            # S[0,2] + S[1,2] > 0 => S(1,1,-1) <= S(1,1,1), S(-1,1,1)
            # -l2, -l1+l2, l3, l1-l3 with the sums -l1, -l1+l2+l3, -l2+l3.
            g[0,0] = 0
            g[0,1] =-1
            g[1,0] =-1
    g = I_ext().dot(g)
    S = g.dot (S_buer).dot (g.T)
    assert ( S[0,1] <= 0 and S[0,2] <= 0 and S[1,2] <= 0 and
             S[0,3] <= 0 and S[1,3] <= 0 and S[2,3] <= 0 ), "Reduced S in Buerger_to_Selling:\n" + str(S)
    return g, S

def Buerger_to_Delaunay (S_buer):
    """ Transform Buerger reduced S_buer to a Delaunay reduced symmetric matrix.
    input : Buerger reduced S_del (3x3 symmetric positive-definite matrix)
    output: 3x3 basis transform matrix g and g*S*(g^T)
             such that g S g^T = (sij) is Delaunay reduced. """
    g, S = Buerger_to_Selling (S_buer)
    g2 = np.delete( putMatrixToMoveSmallerDiagonalLeftUpper (S), 3, 0) # Delete the last row.
    S = g2.dot (S).dot (g2.T)
    assert ( S[0,0] <= S[1,1] <= S[2,2] and 
             S[0,0] + S[1,1] + (S[0,1] + S[0,2] + S[1,2])*2 >= 0 ), "Reduced S in Buerger_to_Delaunay:\n" + str(S) + str(g)
    return g2.dot(g), S

if __name__ == '__main__':
    ndim = 3
    # Make a positive-definite matrix S from a basis matrix B.
    B = [np.random.random() for _ in range (ndim*ndim)]
    B = np.array (B).reshape(ndim,ndim)
    S_input = B.dot (B.T)
    S_input = np.array ([
        [0.86991528, 0.18904655, 0.99175761],
        [0.18904655, 0.05520129, 0.22140677],
        [0.99175761, 0.22140677, 1.21499305]])
    print ("* Input S:")
    print (S_input)
    
    g, S = Delaunay_reduction (S_input)
    print ("* g, Delaunay reduced S = g*S*g^T")
    for j in range(ndim):
         print (" ", g[j], S[j])
    print ("* 4x4 form:")
    print ( S_3x3_to_4x4(S) )
