(define (problem basic) (:domain viatge)
    (:objects
        c1 c2 c3 c4 c5 - ciutat
        h1 h2 h3 h4 h5 h6 h7 h8 h9 h10 - hotel
        v1 v2 v3 v4 v5 v6 v7 v8 v9 v10 v11 v12 v13 v14 v15 v16 v17 v18 v19 v20 - vol
        un_dia dos_dies tres_dies - numDies
    )
   (:init
        (= (num un_dia) 1)
        (= (num dos_dies) 2)
        (= (num tres_dies) 3)
        
        
        (= (interes c1) 1)
        (= (interes c2) 2)
        (= (interes c3) 3)
        (= (interes c4) 2)
        (= (interes c5) 1)
        

        (pertany h1 c1)
        (pertany h2 c1)
        (pertany h3 c2)
        (pertany h4 c2)
        (pertany h5 c3)
        (pertany h6 c3)
        (pertany h7 c4)
        (pertany h8 c4)
        (pertany h9 c5)
        (pertany h10 c5)

        (uneix v1 c1 c2)
        (uneix v2 c1 c3)
        (uneix v3 c1 c4)
        (uneix v4 c1 c5)

        (uneix v5 c2 c1)
        (uneix v6 c2 c3)
        (uneix v7 c2 c4)
        (uneix v8 c2 c5)

        (uneix v9 c3 c1)
        (uneix v10 c3 c2)
        (uneix v11 c3 c4)
        (uneix v12 c3 c5)

        (uneix v13 c4 c1)
        (uneix v14 c4 c2)
        (uneix v15 c4 c3)
        (uneix v16 c4 c5)

        (uneix v17 c5 c1)
        (uneix v18 c5 c2)
        (uneix v19 c5 c3)
        (uneix v20 c5 c4)

        (= (ciutats_a_visitar) 2)
        (= (ciutats_visitades) 0)
        (= (dies_totals_visitats) 0)
        (= (min_dies_viatge) 4)
        (= (interes_viatge) 0)
    )

    (:goal
         (acaba)
    )
    (:metric minimize (interes_viatge))
)
