; using a single 512-sample waveform

sr	=	44100
kr	=	4410
ksmps	=	10
nchnls	=	1

instr	1
	imaxamp	=	32767
	kenv	line	imaxamp*p4, p3, 0
	awave	oscil	kenv, cpspch(p5), 2
		out	awave
endin

instr	2 ; same thing, with vibrato capability
	imaxamp	=	32767
	kenv	line	imaxamp*p4, p3, 0
	kvib	linseg	0, p3/2, cpspch(p5)*0.02, p3/2, 0
	avib	oscil	kvib, 6, 1 ; vibrato oscillator
	awave	oscil	kenv, cpspch(p5)+avib, 2
		out	awave
endin

