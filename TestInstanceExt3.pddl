(define (problem basic) (:domain viatge)
    (:objects
        c1 c2 c3 c4 c5 - ciutat
        h1 h2 h3 h4 h5 h6 h7 h8 h9 h10 - hotel
        v1 v2 v3 v4 v5 v6 v7 v8 v9 v10 v11 v12 v13 v14 v15 v16 v17 v18 v19 v20 - vol
        tres_dies dos_dies un_dia - numDies
    )
   (:init
        (= (num un_dia) 1)
        (= (num dos_dies) 2)
        (= (num tres_dies) 3)
        (= (preuV v1) 100)
        (= (preuV v2) 150)
        (= (preuV v3) 200)
        (= (preuV v4) 120)
        (= (preuV v5) 110)
        (= (preuV v6) 220)
        (= (preuV v7) 123)
        (= (preuV v8) 240)
        (= (preuV v9) 170)
        (= (preuV v10) 134)
        (= (preuV v11) 253)
        (= (preuV v12) 299)
        (= (preuV v13) 198)
        (= (preuV v14) 197)
        (= (preuV v15) 290)
        (= (preuV v16) 140)
        (= (preuV v17) 210)
        (= (preuV v18) 209)
        (= (preuV v19) 104)
        (= (preuV v20) 160)

        (= (preuH h1) 30)
        (= (preuH h2) 50)
        (= (preuH h3) 90)
        (= (preuH h4) 25)
        (= (preuH h5) 20)
        (= (preuH h6) 57)
        (= (preuH h7) 78)
        (= (preuH h8) 34)
        (= (preuH h9) 50)
        (= (preuH h10) 87)




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

        (= (ciutats_a_visitar) 4)
        (= (ciutats_visitades) 0)
        (= (dies_actual_viatge) 0)
        (= (min_dies_viatge) 4)
        (= (preuTotalViatge) 0)
        (= (preuMinimViatge) 1800)
        (= (preuMaximViatge) 2000)
        
    )

    (:goal
         (acaba)
    )
    
    (:metric minimize (preuTotalViatge))    

)

