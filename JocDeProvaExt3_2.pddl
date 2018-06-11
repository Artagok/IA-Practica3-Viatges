(define (problem basic) (:domain viatge)
	(:objects
		c1 c2 c3 - ciutat
		h1 h2 h3 h4 h5 h6 - hotel
		v1 v2 v3 v4 v5 v6 - vol
		num_dies_1 num_dies_2 num_dies_3 - numDies
	)
	(:init
		(= (num num_dies_1) 1)
		(= (num num_dies_2) 2)
		(= (num num_dies_3) 3)

		(= (preuV v1) 100)
		(= (preuV v2) 105)
		(= (preuV v3) 100)

		(= (preuV v4) 150)
		(= (preuV v5) 180)
		(= (preuV v6) 200)

		(= (preuH h1) 80)
		(= (preuH h2) 60)
		(= (preuH h3) 55)

        (= (preuH h4) 200)
		(= (preuH h5) 190)
		(= (preuH h6) 195)

		(pertany h1 c1)
		(pertany h2 c2)
		(pertany h3 c3)

    	(pertany h4 c1)
		(pertany h5 c2)
		(pertany h6 c3)

		(uneix v1 c1 c2)
		(uneix v2 c2 c3)
		(uneix v3 c3 c1)

        (uneix v4 c1 c2)
        (uneix v5 c2 c3)
        (uneix v6 c3 c1)

		(= (ciutats_a_visitar) 1)
		(= (ciutats_visitades) 0)
		(= (dies_actual_viatge) 0)
		(= (min_dies_viatge) 1)
		(= (preuTotalViatge) 0)
		(= (preuMinimViatge) 800)
		(= (preuMaximViatge) 9000)
	)

	(:goal
		(acaba)
	)
	(:metric minimize (preuTotalViatge))
)