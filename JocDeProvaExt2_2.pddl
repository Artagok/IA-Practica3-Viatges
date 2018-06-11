(define (problem basic) (:domain viatge)
	(:objects
		c1 c2 c3 c4 c5 c6 c7 - ciutat
		h1 h2 h3 h4 h5 h6 h7 - hotel
		v1 v2 v3 v4 v5 v6 v7 v8 - vol
		num_dies_1 num_dies_2 num_dies_3 - numDies
	)
	(:init
		(= (num num_dies_1) 1)
		(= (num num_dies_2) 2)
		(= (num num_dies_3) 3)

		(= (interes c1) 1)
		(= (interes c2) 3)
		(= (interes c3) 3)
		(= (interes c4) 3)
		(= (interes c5) 1)
		(= (interes c6) 1)
		(= (interes c7) 1)

		(pertany h1 c1)
		(pertany h2 c2)
		(pertany h3 c3)
		(pertany h4 c4)
		(pertany h5 c5)
		(pertany h6 c6)
		(pertany h7 c7)

        (uneix v1 c1 c2)
        (uneix v2 c2 c3)
        (uneix v3 c3 c4)
        (uneix v4 c4 c1)
        (uneix v5 c1 c5)
        (uneix v6 c5 c6)
        (uneix v7 c6 c7)
        (uneix v8 c7 c1)

		(= (ciutats_a_visitar) 1)
		(= (ciutats_visitades) 0)
		(= (dies_actual_viatge) 0)
		(= (min_dies_viatge) 1)
		(= (interes_viatge) 0)
	)

	(:goal
		(acaba)
	)
	(:metric minimize (interes_viatge))
)