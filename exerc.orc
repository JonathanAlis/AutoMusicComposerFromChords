sr = 44100
kr = 441
ksmps = 100
nchnls = 2

instr 1
	ifreq = cpspch(p4)
	iamp = p5 * 15000
	kamp linen 1.0, 0.05, p3, p3 * 0.7
	asig oscil iamp, ifreq, 1
	aout = kamp * asig
	outs aout, aout
endin


instr 2
	ifreq = cpspch(p4)
	iamp = p5 * 15000
	kamp linen 1.0, 0.1 * p3, p3, p3 * 0.3
	asig oscil iamp, ifreq, 2
	aout = kamp * asig
	outs aout, aout
endin