(define (domain viatge)
    (:requirements :strips :fluents :typing :adl)
    (:types vol ciutat hotel numDies - object)

    (:predicates
        (uneix ?v - vol ?c1 - ciutat ?c2 - ciutat)
        (pertany ?h - hotel ?c - ciutat)
        (visitada ?c - ciutat)
        (ciutat_inicial ?c - ciutat)
        (ciutat_final ?c - ciutat)
        (acaba)
    )

    (:functions
        (num ?x - numDies)
        (preuV ?p - vol)
        (preuH ?p - hotel)
        (dies_totals_visitats)
        (min_dies_viatge)
        (ciutats_a_visitar)
        (ciutats_visitades)
        (preuTotalViatge)
    )

    (:action tria_ciutat_inicial
        :parameters (?c - ciutat)
        :precondition (not (exists (?cx - ciutat) (ciutat_inicial ?cx)))
        :effect (and (ciutat_inicial ?c) (visitada ?c))
    )

    (:action visitar_primera_ciutat
        :parameters (?v - vol  ?c1 - ciutat ?c2 - ciutat ?h - hotel ?r - numDies)
        :precondition (and (uneix ?v ?c1 ?c2) (pertany ?h ?c2) (ciutat_inicial ?c1) (not (exists (?y - ciutat) (ciutat_final ?y))))
        :effect (and (ciutat_final ?c2) (visitada ?c2) (increase (ciutats_visitades) 1) (increase (dies_totals_visitats) (num ?r)) (increase (preuTotalViatge)(* (num ?r) (preuH ?h))))
    )

    (:action visitar_seguent_ciutat
        :parameters (?v - vol ?c1 - ciutat ?c2 - ciutat ?h - hotel ?r - numDies)
        :precondition (and (uneix ?v ?c1 ?c2) (pertany ?h ?c2) (ciutat_final ?c1) (not (visitada ?c2)))
        :effect (and (not (ciutat_final ?c1)) (ciutat_final ?c2) (visitada ?c2) (increase (ciutats_visitades) 1) (increase (dies_totals_visitats) (num ?r))  (increase (preuTotalViatge)(* (num ?r) (preuH ?h))))
    )

    (:action acabar
        :parameters (?v - vol ?c1 - ciutat ?c2 - ciutat)
        :precondition (and (uneix ?v ?c1 ?c2) (ciutat_final ?c1) (ciutat_inicial ?c2) (<= (ciutats_a_visitar) (ciutats_visitades)) (>= (dies_totals_visitats) (min_dies_viatge)))
        :effect (and (not (ciutat_final ?c1)) (not (ciutat_inicial ?c2)) (acaba))
    )

)
