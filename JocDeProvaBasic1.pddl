(define (problem basic) (:domain viatge)
	(:objects
		c1 c2 c3 c4 c5 - ciutat
		h1 h2 h3 h4 h5 - hotel
		v1 v2 v3 v4 v5 v6 v7 - vol
	)
	(:init
		(pertany h1 c1)
		(pertany h2 c2)
		(pertany h3 c3)
		(pertany h4 c4)
		(pertany h5 c5)

		(uneix v1 c1 c2)
		
		(uneix v2 c2 c3)
		(uneix v3 c2 c1)

		(uneix v3 c3 c4)
		(uneix v4 c3 c1)

		(uneix v5 c4 c5)
		(uneix v6 c4 c1)

		(uneix v7 c5 c1)

		(= (ciutats_a_visitar) 4)
		(= (ciutats_visitades) 0)
	)

	(:goal
		(acaba)
	)
)