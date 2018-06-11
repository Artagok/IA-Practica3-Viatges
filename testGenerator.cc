#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>    /* Pel la seed del random necessitem time */

void basic() {

    srand(time(0));
    std::ofstream ofs;
    ofs.open("TestInstanceBasic.pddl", std::ofstream::out | std::ofstream::trunc);

    /* HEADER */
    std::string file = "(define (problem basic) (:domain viatge)\n";
    file += "\t(:objects\n";

    std::cout << "Quantes ciutats vols que hi hagi? (#ciutats >= 2)" << std::endl;
    int n_ciutats;
    std::cin >> n_ciutats;

    /* CIUTATS */
    file += "\t\t";
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "c";
        file += std::to_string(i);
        file += " ";
    }
    file += "- ciutat\n\t\t";

    /* HOTELS */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "h";
        file += std::to_string(i);
        file += " ";
    }
    file += "- hotel\n\t\t";

    std::cout << "Assumim que totes les ciutats estan connectades entre sí" << std::endl;

    /* VOLS */
    for (int i = 1; i <= n_ciutats*(n_ciutats-1); ++i) {
        file += "v";
        file += std::to_string(i);
        file += " ";
    }
    file += "- vol\n\t)\n";

    /* INIT */
    file += "\t(:init\n";
   
    /* pertany */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "\t\t(pertany ";
        file = file + "h" + std::to_string(i) + " " + "c" + std::to_string(i) + ")\n";
    }
    file += "\n";

    /* uneix */
    int index_vol = 1;
    for (int i = 1; i <= n_ciutats; ++i) {
        for (int j = 1; j <= n_ciutats; ++j) {
            if (i != j) {
                file += "\t\t(uneix ";
                file = file + "v" + std::to_string(index_vol) + " c" + std::to_string(i) + " c" + std::to_string(j) + ")\n";
                ++index_vol;
            }
        }
    }
    file += "\n";

    /* variables numeriques */
    int ctv = ( rand() % (n_ciutats-1) ) + 1;
    file = file + "\t\t(= (ciutats_a_visitar) " + std::to_string(ctv) + ")\n";
    std::cout << "#ciutats_a_visitar escollit random (en aquesta execució " << ctv << " ciutat(s) a visitar)" << std::endl;
    file = file + "\t\t(= (ciutats_visitades) 0)\n";

    file += "\t)\n\n";
    file += "\t(:goal\n";
    file += "\t\t(acaba)\n";
    file += "\t)\n)";

    ofs.write(file.c_str(),file.size());
}

void ext1() {

    srand(time(0));
    std::ofstream ofs;
    ofs.open("TestInstanceExt1.pddl", std::ofstream::out | std::ofstream::trunc);

    /* HEADER */
    std::string file = "(define (problem basic) (:domain viatge)\n";
    file += "\t(:objects\n";

    std::cout << "Quantes ciutats vols que hi hagi? (#ciutats >= 2)" << std::endl;
    int n_ciutats;
    std::cin >> n_ciutats;

    /* CIUTATS */
    file += "\t\t";
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "c";
        file += std::to_string(i);
        file += " ";
    }
    file += "- ciutat\n\t\t";
    
    /* HOTELS */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "h";
        file += std::to_string(i);
        file += " ";
    }
    file += "- hotel\n\t\t";

    std::cout << "Assumim que totes les ciutats estan connectades entre sí" << std::endl;

    /* VOLS */
    for (int i = 1; i <= n_ciutats*(n_ciutats-1); ++i) {
        file += "v";
        file += std::to_string(i);
        file += " ";
    }
    file += "- vol\n";

    /* MIN/MAX DIES A CADA CIUTAT */
    std::cout << "Introdueix el nombre mínim de dies a cada ciutat" << std::endl;
    int minim_dies;
    std::cin >> minim_dies;
    std::cout << "Introdueix el nombre màxim de dies a cada ciutat" << std::endl;
    int maxim_dies;
    std::cin >> maxim_dies;

    file += "\t\t";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
        else {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
    }
    file += "- numDies\n\t)\n";

    /* INIT */
    file += "\t(:init\n";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";
        }
        else {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";   
        }
    }
    file += "\n";

    /* pertany */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "\t\t(pertany ";
        file = file + "h" + std::to_string(i) + " " + "c" + std::to_string(i) + ")\n";
    }
    file += "\n";

    /* uneix */
    int index_vol = 1;
    for (int i = 1; i <= n_ciutats; ++i) {
        for (int j = 1; j <= n_ciutats; ++j) {
            if (i != j) {
                file += "\t\t(uneix ";
                file = file + "v" + std::to_string(index_vol) + " c" + std::to_string(i) + " c" + std::to_string(j) + ")\n";
                ++index_vol;
            }
        }
    }
    file += "\n";

    /* variables numeriques */
    int ctv = (rand()%(n_ciutats-1))+1;
    file = file + "\t\t(= (ciutats_a_visitar) " + std::to_string(ctv) + ")\n";
    std::cout << "#ciutats_a_visitar escollit random (en aquesta execució " << ctv << " ciutat(s) a visitar)" << std::endl;    
    file = file + "\t\t(= (ciutats_visitades) 0)\n";
    file = file + "\t\t(= (dies_actual_viatge) 0)\n";
    std::cout << "Quants dies ha de durar el viatge com a mínim?" << std::endl;
    int minim_dies_viatge;
    std::cin >> minim_dies_viatge;
    file = file + "\t\t(= (min_dies_viatge) " + std::to_string(minim_dies_viatge) + ")\n";

    file += "\t)\n\n";
    file += "\t(:goal\n";
    file += "\t\t(acaba)\n";
    file += "\t)\n)";

    ofs.write(file.c_str(),file.size());
}

void ext2() {

    srand(time(0));
    std::ofstream ofs;
    ofs.open("TestInstanceExt2.pddl", std::ofstream::out | std::ofstream::trunc);

    /* HEADER */
    std::string file = "(define (problem basic) (:domain viatge)\n";
    file += "\t(:objects\n";

    std::cout << "Quantes ciutats vols que hi hagi? (#ciutats >= 2)" << std::endl;
    int n_ciutats;
    std::cin >> n_ciutats;

    /* CIUTATS */
    file += "\t\t";
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "c";
        file += std::to_string(i);
        file += " ";
    }
    file += "- ciutat\n\t\t";
    
    /* HOTELS */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "h";
        file += std::to_string(i);
        file += " ";
    }
    file += "- hotel\n\t\t";

    std::cout << "Assumim que totes les ciutats estan connectades entre sí" << std::endl;

    /* VOLS */
    for (int i = 1; i <= n_ciutats*(n_ciutats-1); ++i) {
        file += "v";
        file += std::to_string(i);
        file += " ";
    }
    file += "- vol\n";

    /* MIN/MAX DIES A CADA CIUTAT */
    std::cout << "Introdueix el nombre mínim de dies a cada ciutat" << std::endl;
    int minim_dies;
    std::cin >> minim_dies;
    std::cout << "Introdueix el nombre màxim de dies a cada ciutat" << std::endl;
    int maxim_dies;
    std::cin >> maxim_dies;

    file += "\t\t";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
        else {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
    }
    file += "- numDies\n\t)\n";

    /* INIT */
    file += "\t(:init\n";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";
        }
        else {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";   
        }
    }
    file += "\n";

    /* interes de cada ciutat */
    std::cout << "Interés de cada ciutat generat random entre 1 i 3" << std::endl;
    for (int i = 1; i <= n_ciutats; ++i) {
        file = file + "\t\t(= (interes c" + std::to_string(i) + ") " + std::to_string((rand()%3)+1) + ")\n";
    }
    file += "\n";

    /* pertany */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "\t\t(pertany ";
        file = file + "h" + std::to_string(i) + " " + "c" + std::to_string(i) + ")\n";
    }
    file += "\n";

    /* uneix */
    int index_vol = 1;
    for (int i = 1; i <= n_ciutats; ++i) {
        for (int j = 1; j <= n_ciutats; ++j) {
            if (i != j) {
                file += "\t\t(uneix ";
                file = file + "v" + std::to_string(index_vol) + " c" + std::to_string(i) + " c" + std::to_string(j) + ")\n";
                ++index_vol;
            }
        }
    }
    file += "\n";

    /* variables numeriques */
    int ctv = (rand()%(n_ciutats-1))+1;
    file = file + "\t\t(= (ciutats_a_visitar) " + std::to_string(ctv) + ")\n";
    std::cout << "#ciutats_a_visitar escollit random (en aquesta execució " << ctv << " ciutat(s) a visitar)" << std::endl;    
    file = file + "\t\t(= (ciutats_visitades) 0)\n";
    file = file + "\t\t(= (dies_actual_viatge) 0)\n";
    std::cout << "Quants dies ha de durar el viatge com a mínim?" << std::endl;
    int minim_dies_viatge;
    std::cin >> minim_dies_viatge;
    file = file + "\t\t(= (min_dies_viatge) " + std::to_string(minim_dies_viatge) + ")\n";
    file = file + "\t\t(= (interes_viatge) 0)\n";

    file += "\t)\n\n";
    file += "\t(:goal\n";
    file += "\t\t(acaba)\n";
    file += "\t)\n";
    file += "\t(:metric minimize (interes_viatge))\n";
    file += ")";

    ofs.write(file.c_str(),file.size());
}

void ext3() {

    srand(time(0));
    std::ofstream ofs;
    ofs.open("TestInstanceExt3.pddl", std::ofstream::out | std::ofstream::trunc);

    /* HEADER */
    std::string file = "(define (problem basic) (:domain viatge)\n";
    file += "\t(:objects\n";

    std::cout << "Quantes ciutats vols que hi hagi? (#ciutats >= 2)" << std::endl;
    int n_ciutats;
    std::cin >> n_ciutats;

    /* CIUTATS */
    file += "\t\t";
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "c";
        file += std::to_string(i);
        file += " ";
    }
    file += "- ciutat\n\t\t";
    
    /* HOTELS */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "h";
        file += std::to_string(i);
        file += " ";
    }
    file += "- hotel\n\t\t";

    std::cout << "Assumim que totes les ciutats estan connectades entre sí" << std::endl;

    /* VOLS */
    for (int i = 1; i <= n_ciutats*(n_ciutats-1); ++i) {
        file += "v";
        file += std::to_string(i);
        file += " ";
    }
    file += "- vol\n";

    /* MIN/MAX DIES A CADA CIUTAT */
    std::cout << "Introdueix el nombre mínim de dies a cada ciutat" << std::endl;
    int minim_dies;
    std::cin >> minim_dies;
    std::cout << "Introdueix el nombre màxim de dies a cada ciutat" << std::endl;
    int maxim_dies;
    std::cin >> maxim_dies;

    file += "\t\t";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
        else {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
    }
    file += "- numDies\n\t)\n";

    /* INIT */
    file += "\t(:init\n";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";
        }
        else {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";   
        }
    }
    file += "\n";

    /* preu vols */
    for (int i = 1; i <= n_ciutats*(n_ciutats-1); ++i) {
        file = file + "\t\t(= (preuV v" + std::to_string(i) + ") " + std::to_string((rand()%101)+100) + ")\n";
    }
    file += "\n";

    /* preu hotels */
    for (int i = 1; i <= n_ciutats; ++i) {
        file = file + "\t\t(= (preuH h" + std::to_string(i) + ") " + std::to_string((rand()%101)+20) + ")\n";
    }
    file += "\n";

    /* pertany */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "\t\t(pertany ";
        file = file + "h" + std::to_string(i) + " " + "c" + std::to_string(i) + ")\n";
    }
    file += "\n";

    /* uneix */
    int index_vol = 1;
    for (int i = 1; i <= n_ciutats; ++i) {
        for (int j = 1; j <= n_ciutats; ++j) {
            if (i != j) {
                file += "\t\t(uneix ";
                file = file + "v" + std::to_string(index_vol) + " c" + std::to_string(i) + " c" + std::to_string(j) + ")\n";
                ++index_vol;
            }
        }
    }
    file += "\n";

    /* variables numeriques */
    int ctv = (rand()%(n_ciutats-1))+1;
    file = file + "\t\t(= (ciutats_a_visitar) " + std::to_string(ctv) + ")\n";
    std::cout << "#ciutats_a_visitar escollit random (en aquesta execució " << ctv << " ciutat(s) a visitar)" << std::endl;    
    file = file + "\t\t(= (ciutats_visitades) 0)\n";
    file = file + "\t\t(= (dies_actual_viatge) 0)\n";
    std::cout << "Quants dies ha de durar el viatge com a mínim?" << std::endl;
    int minim_dies_viatge;
    std::cin >> minim_dies_viatge;
    file = file + "\t\t(= (min_dies_viatge) " + std::to_string(minim_dies_viatge) + ")\n";
    std::cout << "Quin és el cost mínim del viatge?" << std::endl;
    file = file + "\t\t(= (preuTotalViatge) 0)\n";    
    int preu_minim_viatge;
    std::cin >> preu_minim_viatge;
    file = file + "\t\t(= (preuMinimViatge) " + std::to_string(preu_minim_viatge) + ")\n";
    std::cout << "Quin és el cost màxim del viatge?" << std::endl;    
    int preu_maxim_viatge;
    std::cin >> preu_maxim_viatge;
    file = file + "\t\t(= (preuMaximViatge) " + std::to_string(preu_maxim_viatge) + ")\n";

    file += "\t)\n\n";
    file += "\t(:goal\n";
    file += "\t\t(acaba)\n";
    file += "\t)\n";
    file += "\t(:metric minimize (preuTotalViatge))\n";
    file += ")";

    ofs.write(file.c_str(),file.size());
}

void ext4() {

    srand(time(0));
    std::ofstream ofs;
    ofs.open("TestInstanceExt4.pddl", std::ofstream::out | std::ofstream::trunc);

    /* HEADER */
    std::string file = "(define (problem basic) (:domain viatge)\n";
    file += "\t(:objects\n";

    std::cout << "Quantes ciutats vols que hi hagi? (#ciutats >= 2)" << std::endl;
    int n_ciutats;
    std::cin >> n_ciutats;

    /* CIUTATS */
    file += "\t\t";
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "c";
        file += std::to_string(i);
        file += " ";
    }
    file += "- ciutat\n\t\t";
    
    /* HOTELS */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "h";
        file += std::to_string(i);
        file += " ";
    }
    file += "- hotel\n\t\t";

    std::cout << "Assumim que totes les ciutats estan connectades entre sí" << std::endl;

    /* VOLS */
    for (int i = 1; i <= n_ciutats*(n_ciutats-1); ++i) {
        file += "v";
        file += std::to_string(i);
        file += " ";
    }
    file += "- vol\n";

    /* MIN/MAX DIES A CADA CIUTAT */
    std::cout << "Introdueix el nombre mínim de dies a cada ciutat" << std::endl;
    int minim_dies;
    std::cin >> minim_dies;
    std::cout << "Introdueix el nombre màxim de dies a cada ciutat" << std::endl;
    int maxim_dies;
    std::cin >> maxim_dies;

    file += "\t\t";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
        else {
            file = file +  "num_dies_" + std::to_string(i) + " ";
        }
    }
    file += "- numDies\n\t)\n";

    /* INIT */
    file += "\t(:init\n";
    for (int i = minim_dies; i <= maxim_dies; ++i) {
        if (i == 1) {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";
        }
        else {
            file = file + "\t\t(= (num " + "num_dies_" + std::to_string(i) + ") " + std::to_string(i) + ")\n";   
        }
    }
    file += "\n";

    /* preu vols */
    for (int i = 1; i <= n_ciutats*(n_ciutats-1); ++i) {
        file = file + "\t\t(= (preuV v" + std::to_string(i) + ") " + std::to_string((rand()%101)+100) + ")\n";
    }
    file += "\n";

    /* preu hotels */
    for (int i = 1; i <= n_ciutats; ++i) {
        file = file + "\t\t(= (preuH h" + std::to_string(i) + ") " + std::to_string((rand()%101)+20) + ")\n";
    }
    file += "\n";

    /* interes de cada ciutat */
    std::cout << "Interés de cada ciutat generat random entre 1 i 3" << std::endl;
    for (int i = 1; i <= n_ciutats; ++i) {
        file = file + "\t\t(= (interes c" + std::to_string(i) + ") " + std::to_string((rand()%3)+1) + ")\n";
    }
    file += "\n";

    /* pertany */
    for (int i = 1; i <= n_ciutats; ++i) {
        file += "\t\t(pertany ";
        file = file + "h" + std::to_string(i) + " " + "c" + std::to_string(i) + ")\n";
    }
    file += "\n";

    /* uneix */
    int index_vol = 1;
    for (int i = 1; i <= n_ciutats; ++i) {
        for (int j = 1; j <= n_ciutats; ++j) {
            if (i != j) {
                file += "\t\t(uneix ";
                file = file + "v" + std::to_string(index_vol) + " c" + std::to_string(i) + " c" + std::to_string(j) + ")\n";
                ++index_vol;
            }
        }
    }
    file += "\n";

    /* variables numeriques */
    int ctv = (rand()%(n_ciutats-1))+1;
    file = file + "\t\t(= (ciutats_a_visitar) " + std::to_string(ctv) + ")\n";
    std::cout << "#ciutats_a_visitar escollit random (en aquesta execució " << ctv << " ciutat(s) a visitar)" << std::endl;    
    file = file + "\t\t(= (ciutats_visitades) 0)\n";
    file = file + "\t\t(= (dies_actual_viatge) 0)\n";
    std::cout << "Quants dies ha de durar el viatge com a mínim?" << std::endl;
    int minim_dies_viatge;
    std::cin >> minim_dies_viatge;
    file = file + "\t\t(= (min_dies_viatge) " + std::to_string(minim_dies_viatge) + ")\n";
     std::cout << "Quin és el cost mínim del viatge?" << std::endl;
    file = file + "\t\t(= (preuTotalViatge) 0)\n";    
    int preu_minim_viatge;
    std::cin >> preu_minim_viatge;
    file = file + "\t\t(= (preuMinimViatge) " + std::to_string(preu_minim_viatge) + ")\n";
    std::cout << "Quin és el cost màxim del viatge?" << std::endl;    
    int preu_maxim_viatge;
    std::cin >> preu_maxim_viatge;
    file = file + "\t\t(= (preuMaximViatge) " + std::to_string(preu_maxim_viatge) + ")\n";
    file = file + "\t\t(= (interes_viatge) 0)\n";

    file += "\t)\n\n";
    file += "\t(:goal\n";
    file += "\t\t(acaba)\n";
    file += "\t)\n";
    file += "\t(:metric minimize (+ (* 2 (preuTotalViatge)) (* (/ (+ (preuMinimViatge) (preuMaximViatge)) 2) (interes_viatge))))\n";
    file += ")";

    ofs.write(file.c_str(),file.size());
}

int main() {
    
    std::cout << std::endl;
    std::cout << "Per a quina extensió vols generar el test?" << std::endl;
    std::cout << "Basic: 0" << std::endl;
    std::cout << "Ext1:  1" << std::endl;
    std::cout << "Ext2:  2" << std::endl;
    std::cout << "Ext3:  3" << std::endl;
    std::cout << "Ext4:  4" << std::endl;

    int extensio;
    std::cin >> extensio;

    switch(extensio) {
        
        case 0:
            basic();
            break;
        
        case 1:
            ext1();
            break;

        case 2:
            ext2();
            break;

        case 3:
            ext3();
            break;

        case 4:
            ext4();
            break;
        
        default:
            std::cout << "Input incorrecte, tria entre: 0,1,2,3,4" << std::endl;
            break;    
    }
}