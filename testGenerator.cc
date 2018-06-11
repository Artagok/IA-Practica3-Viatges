#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

void basic() {

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
    std::cout << "#ciutats_a_visitar escollit random" << std::endl;
    file = file + "\t\t(= (ciutats_a_visitar) " + std::to_string(rand()%(n_ciutats-1)+1) + ")\n";
    file = file + "\t\t(= (ciutats_visitades) 0)\n";

    file += "\t)\n\n";
    file += "(:goal\n";
    file += "\t\t(acaba)\n";
    file += "\t)\n)";

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
            //ext1();
            break;

        case 2:
            //ext2();
            break;

        case 3:
            //ext3();
            break;

        case 4:
            //ext4();
            break;
        
        default:
            std::cout << "Input incorrecte, tria entre: 0,1,2,3,4" << std::endl;
            break;    
    }
}