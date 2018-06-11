(define (domain viatge)
    (:requirements :strips :fluents :typing :adl)
    (:types vol ciutat hotel numDies - object)

    (:predicates
        (uneix ?v - vol ?c1 - ciutat ?c2 - ciutat)
        (pertany ?h - hotel ?c - ciutat)
        (visitada ?c - ciutat)
        (ciutat_inicial ?c - ciutat)
        (ultima_ciutat ?c - ciutat)
        (acaba)
    )

    (:functions
        (interes ?i - ciutat)
        (num ?n - numDies)
        (dies_totals_visitats)
        (min_dies_viatge)
        (ciutats_a_visitar)
        (ciutats_visitades)
        (interes_viatge)
    )

    (:action tria_ciutat_inicial
        :parameters (?c - ciutat)
        :precondition (not (exists (?cx - ciutat) 
                        (ciutat_inicial ?cx)))
        :effect (and (ciutat_inicial ?c) 
                        (visitada ?c))
    )

    (:action visitar_primera_ciutat
        :parameters (?v - vol  ?c1 - ciutat ?c2 - ciutat ?h - hotel ?r - numDies)
        :precondition (and (uneix ?v ?c1 ?c2) 
                    (pertany ?h ?c2) 
                    (ciutat_inicial ?c1) 
                    (not (exists (?y - ciutat) (ultima_ciutat ?y))))
        :effect (and (ultima_ciutat ?c2) 
                    (visitada ?c2) 
                    (increase (interes_viatge) (interes ?c2)) 
                    (increase (ciutats_visitades) 1) 
                    (increase (dies_totals_visitats) (num ?r)))
    )

    (:action visitar_seguent_ciutat
        :parameters (?v - vol ?c1 - ciutat ?c2 - ciutat ?h - hotel ?r - numDies)
        :precondition (and (uneix ?v ?c1 ?c2) 
                        (pertany ?h ?c2) 
                        (ultima_ciutat ?c1) 
                        (not (visitada ?c2)))
        :effect (and (not (ultima_ciutat ?c1)) 
                        (ultima_ciutat ?c2) 
                        (visitada ?c2) 
                        (increase (ciutats_visitades) 1) 
                        (increase (dies_totals_visitats) (num ?r)) 
                        (increase (interes_viatge) (interes ?c2)))
    )

    (:action acabar
        :parameters (?v - vol ?c1 - ciutat ?c2 - ciutat)
        :precondition (and (uneix ?v ?c1 ?c2) 
                    (ultima_ciutat ?c1) 
                    (ciutat_inicial ?c2) 
                    (<= (ciutats_a_visitar) (ciutats_visitades)) 
                    (>= (dies_totals_visitats) (min_dies_viatge)))
        :effect (acaba)
    )

)
