(define (problem basic) (:domain viatge)
	(:objects
		c1 c2 c3 - ciutat
		h1 h2 h3 - hotel
		v1 v2 v3 v4 - vol
		num_dies_1 num_dies_2 num_dies_3 - numDies
	)
	(:init
		(= (num num_dies_1) 1)
		(= (num num_dies_2) 2)
		(= (num num_dies_3) 3)

		(= (preuV v1) 80)
		(= (preuV v2) 90)
		(= (preuV v3) 175)
		(= (preuV v4) 140)

		(= (preuH h1) 30)
		(= (preuH h2) 40)
		(= (preuH h3) 80)

		(= (interes c1) 1)
		(= (interes c2) 1)
		(= (interes c3) 1)

		(pertany h1 c1)
		(pertany h2 c2)
		(pertany h3 c3)

		(uneix v1 c1 c2)
		(uneix v2 c2 c1)
		(uneix v3 c1 c3)
		(uneix v4 c3 c1)

		(= (ciutats_a_visitar) 1)
		(= (ciutats_visitades) 0)
		(= (dies_actual_viatge) 0)
		(= (min_dies_viatge) 1)
		(= (preuTotalViatge) 0)
		(= (preuMinimViatge) 0)
		(= (preuMaximViatge) 9000)
		(= (interes_viatge) 0)
	)

	(:goal
		(acaba)
	)
	(:metric minimize (+ (* 2 (preuTotalViatge)) (* (/ (+ (preuMinimViatge) (preuMaximViatge)) 2) (interes_viatge))))
)