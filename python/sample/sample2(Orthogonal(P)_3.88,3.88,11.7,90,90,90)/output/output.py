''' << Unit-cell Parameters with the Minimal Distance >>
Bravais_type, Number_of_candidates, a b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
       Cubic(F)  0
       Cubic(I)  0
       Cubic(P)  0
      Hexagonal  0
   Rhombohedral  2  4.4804e+00  4.4804e+00  3.6015e+01  9.0000e+01  9.0000e+01  1.2000e+02  5.0001e+01
  Tetragonal(I)  0
  Tetragonal(P)  3  3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02
Orthorhombic(F)  1  5.4860e+00  5.4914e+00  2.3941e+01  9.0000e+01  9.0000e+01  9.0000e+01  4.2435e+01
Orthorhombic(I)  0
Orthorhombic(C)  9  5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  7.9600e-02
Orthorhombic(P)  3  3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02
  Monoclinic(C)  9  5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0040e+01  9.0000e+01  4.7836e-02
  Monoclinic(P)  3  3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0039e+01  9.0000e+01  2.9212e-02
      Triclinic  1  3.8792e+00  3.8830e+00  1.1654e+01  9.0018e+01  9.0039e+01  9.0057e+01  0.0000e+00
'''
AllCandidates = {
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Cubic(F)' : [
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Cubic(I)' : [
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Cubic(P)' : [
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Hexagonal' : [
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Rhombohedral' : [
		'4.4804e+00  4.4804e+00  3.6015e+01  9.0000e+01  9.0000e+01  1.2000e+02  5.0001e+01',
		'4.4804e+00  4.4804e+00  3.6018e+01  9.0000e+01  9.0000e+01  1.2000e+02  5.0084e+01'
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Tetragonal(I)' : [
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Tetragonal(P)' : [
		'3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02',
		'3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02',
		'3.8811e+00  3.8811e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.6411e-02'
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Orthorhombic(F)' : [
		'5.4860e+00  5.4914e+00  2.3941e+01  9.0000e+01  9.0000e+01  9.0000e+01  4.2435e+01'
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Orthorhombic(I)' : [
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Orthorhombic(C)' : [
		'5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  7.9600e-02',
		'5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  7.9600e-02',
		'3.8792e+00  2.3626e+01  3.8830e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1194e+01',
		'3.8792e+00  2.3626e+01  3.8830e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1194e+01',
		'3.8830e+00  2.3628e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1283e+01',
		'3.8830e+00  2.3628e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  2.1283e+01',
		'3.8830e+00  2.3941e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  3.0006e+01',
		'3.8830e+00  2.4863e+01  3.8792e+00  9.0000e+01  9.0000e+01  9.0000e+01  4.7471e+01',
		'3.8792e+00  2.4866e+01  3.8830e+00  9.0000e+01  9.0000e+01  9.0000e+01  4.7549e+01'
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Orthorhombic(P)' : [
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02',
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02',
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0000e+01  9.0000e+01  5.2414e-02'
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Monoclinic(C)' : [
		'5.4860e+00  5.4914e+00  1.1654e+01  9.0000e+01  9.0040e+01  9.0000e+01  4.7836e-02',
		'5.4914e+00  5.4860e+00  1.1654e+01  9.0000e+01  9.0015e+01  9.0000e+01  7.6079e-02',
		'2.3626e+01  3.8792e+00  3.8830e+00  9.0000e+01  9.0027e+01  9.0000e+01  2.1194e+01',
		'3.8792e+00  2.3626e+01  3.8830e+00  9.0000e+01  9.0057e+01  9.0000e+01  2.1194e+01',
		'2.3628e+01  3.8830e+00  3.8792e+00  9.0000e+01  9.0048e+01  9.0000e+01  2.1283e+01',
		'3.8830e+00  2.3628e+01  3.8792e+00  9.0000e+01  9.0057e+01  9.0000e+01  2.1283e+01',
		'3.8830e+00  2.3941e+01  3.8792e+00  9.0000e+01  9.0057e+01  9.0000e+01  3.0006e+01',
		'3.8830e+00  2.4863e+01  3.8792e+00  9.0000e+01  9.0057e+01  9.0000e+01  4.7471e+01',
		'3.8792e+00  2.4866e+01  3.8830e+00  9.0000e+01  9.0057e+01  9.0000e+01  4.7549e+01'
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Monoclinic(P)' : [
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0000e+01  9.0039e+01  9.0000e+01  2.9212e-02',
		'3.8792e+00  1.1654e+01  3.8830e+00  9.0000e+01  9.0057e+01  9.0000e+01  4.7938e-02',
		'3.8830e+00  3.8792e+00  1.1654e+01  9.0000e+01  9.0018e+01  9.0000e+01  4.8404e-02'
	],
	# a, b, c, alpha, beta, gamma, Distance_from_the_input_unit_cell
	'Triclinic' : [
		'3.8792e+00  3.8830e+00  1.1654e+01  9.0018e+01  9.0039e+01  9.0057e+01  0.0000e+00'
	]
}
