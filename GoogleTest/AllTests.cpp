//
// Created by andrea on 15/12/23.
//
#include "gtest/gtest.h"
#include "QApplication"

int main(int argc, char** argv) {  // Classe per fa viaggiare tutti i test insieme
    QApplication app(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}