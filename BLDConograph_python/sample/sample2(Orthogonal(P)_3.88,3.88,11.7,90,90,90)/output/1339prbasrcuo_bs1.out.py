sampleName = '1339prbasrcuo_bs1'
# Result is divided 2 parts of BravaisLatticeMinDistance & BravaisCandidates.
# BravaisLatticeMinDistance : Selected Bravais lattice parameters of Minimum distance
# BravaisCandidates : Lists of all candidates of lattice parameters
'''
<<Lattice Parameters Minimum Distance>>
PatternName numCandidate, a b, c, alpha, beta, gamma, dist
      Triclinic  1  3.8792e+00  3.8830e+00  1.1654e+01  9.0018e+01  9.0039e+01  9.0057e+01  0.0000e+00
  Monoclinic(P)  3  3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0039e+01  9.0000e+01  2.9212e-02
  Monoclinic(C)  12  5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0040e+01  9.0000e+01  4.7836e-02
Orthorhombic(P)  3  3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02
Orthorhombic(C)  12  5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  7.9600e-02
Orthorhombic(I)  0
Orthorhombic(F)  1  5.4860e+00  5.4914e+00  2.3941e+01  9.0000e+01  9.0000e+01  9.0000e+01  4.2435e+01
  Tetragonal(P)  3  3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02
  Tetragonal(I)  0
   Rhombohedral  2  4.4804e+00  4.4804e+00  3.6015e+01  9.0000e+01  9.0000e+01  1.2000e+02  5.0001e+01
      Hexagonal  0
       Cubic(P)  0
       Cubic(I)  0
       Cubic(F)  0
'''
BravaisCandidates = {
	# a, b, c, alpha, beta, gamma, dist
	'Triclinic' : [
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0018e+01  9.0039e+01  9.0057e+01  0.0000e+00'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Monoclinic(P)' : [
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0039e+01  9.0000e+01  2.9212e-02',
		'3.8792e+00  1.1654e+01  3.8830e+00  9.0000e+01  9.0057e+01  9.0000e+01  4.7938e-02',
		'3.8830e+00  3.8792e+00  1.1654e+01  9.0000e+01  9.0018e+01  9.0000e+01  4.8404e-02'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Monoclinic(C)' : [
		'5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0040e+01  9.0000e+01  4.7836e-02',
		'5.4914e+00  5.4860e+00  1.1654e+01  9.0000e+01  9.0015e+01  9.0000e+01  7.6079e-02',
		'2.3626e+01  3.8792e+00  3.8830e+00  9.0000e+01  9.0027e+01  9.0000e+01  2.1194e+01',
		'3.8792e+00  2.3626e+01  3.8830e+00  9.0000e+01  9.0057e+01  9.0000e+01  2.1194e+01',
		'5.4914e+00  5.4860e+00  1.2283e+01  9.0000e+01  1.0294e+02  9.0000e+01  2.1238e+01',
		'5.4860e+00  5.4914e+00  1.2280e+01  9.0000e+01  1.0285e+02  9.0000e+01  2.1279e+01',
		'2.3628e+01  3.8830e+00  3.8792e+00  9.0000e+01  9.0048e+01  9.0000e+01  2.1283e+01',
		'3.8830e+00  2.3628e+01  3.8792e+00  9.0000e+01  9.0057e+01  9.0000e+01  2.1283e+01',
		'5.4860e+00  5.4914e+00  1.2283e+01  9.0000e+01  1.0288e+02  9.0000e+01  2.1368e+01',
		'3.8830e+00  2.3941e+01  3.8792e+00  9.0000e+01  9.0057e+01  9.0000e+01  3.0006e+01',
		'3.8830e+00  2.4863e+01  3.8792e+00  9.0000e+01  9.0057e+01  9.0000e+01  4.7471e+01',
		'3.8792e+00  2.4866e+01  3.8830e+00  9.0000e+01  9.0057e+01  9.0000e+01  4.7549e+01'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Orthorhombic(P)' : [
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02',
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02',
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Orthorhombic(C)' : [
		'5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  7.9600e-02',
		'5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  7.9600e-02',
		'3.8792e+00  2.3626e+01  3.8830e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1194e+01',
		'3.8792e+00  2.3626e+01  3.8830e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1194e+01',
		'3.8830e+00  2.3628e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1283e+01',
		'3.8830e+00  2.3628e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1283e+01',
		'3.8830e+00  2.3941e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  3.0006e+01',
		'5.4860e+00  5.4914e+00  1.2280e+01  9.0000e+01  9.0000e+01  9.0000e+01  3.0035e+01',
		'5.4860e+00  5.4914e+00  1.2283e+01  9.0000e+01  9.0000e+01  9.0000e+01  3.0127e+01',
		'5.4860e+00  5.4914e+00  1.2283e+01  9.0000e+01  9.0000e+01  9.0000e+01  3.0127e+01',
		'3.8830e+00  2.4863e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  4.7471e+01',
		'3.8792e+00  2.4866e+01  3.8830e+00  9.0000e+01  9.0000e+01  9.0000e+01  4.7549e+01'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Orthorhombic(I)' : [
	],
	# a, b, c, alpha, beta, gamma, dist
	'Orthorhombic(F)' : [
		'5.4860e+00  5.4914e+00  2.3941e+01  9.0000e+01  9.0000e+01  9.0000e+01  4.2435e+01'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Tetragonal(P)' : [
		'3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02',
		'3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02',
		'3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Tetragonal(I)' : [
	],
	# a, b, c, alpha, beta, gamma, dist
	'Rhombohedral' : [
		'4.4804e+00  4.4804e+00  3.6015e+01  9.0000e+01  9.0000e+01  1.2000e+02  5.0001e+01',
		'4.4804e+00  4.4804e+00  3.6018e+01  9.0000e+01  9.0000e+01  1.2000e+02  5.0084e+01'
	],
	# a, b, c, alpha, beta, gamma, dist
	'Hexagonal' : [
	],
	# a, b, c, alpha, beta, gamma, dist
	'Cubic(P)' : [
	],
	# a, b, c, alpha, beta, gamma, dist
	'Cubic(I)' : [
	],
	# a, b, c, alpha, beta, gamma, dist
	'Cubic(F)' : [
	],
}