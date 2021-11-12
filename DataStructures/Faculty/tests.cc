#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "group.hh"
#include "subject.hh"

TEST(SubjectTests, CreateEmptySubject) {
    Subject subj = Subject{};
    std::stringstream ss;
    ss << subj;
    std::string s = ss.str();
    ASSERT_EQ(s, ": 0\n");    
}

TEST(SubjectTests, FillSubject) {
    Subject subj = Subject{};
    std::string data = "Algebra 5";
    std::stringstream ss(data);
    ss >> subj;
    std::stringstream ss1;
    ss1 << subj;
    std::string s = ss1.str();
    ASSERT_EQ(s, "Algebra: 5\n");
}

TEST(StudentTests, CreateEmptyStudent) {
    Student stud = Student();

    std::stringstream ss;
    ss << stud;
    std::string s = ss.str();
    EXPECT_EQ(s, "\n\n: 0\n: 0\n: 0\n: 0\n: 0\n\n");
}

TEST(StudentTests, ReadStudent) {
    Student stud = Student();

    std::string data = "Ivanov\nFree\nAlgebra 4\nGeometry 3\nPhysics 2\nEnglish 4\nHistory 5\n";
    std::stringstream ss(data);
    ss >> stud;
    std::stringstream ss1;
    ss1 << stud;
    std::string stud_s = ss1.str();
    EXPECT_EQ(stud_s, "Ivanov\nFree\nAlgebra: 4\nGeometry: 3\nPhysics: 2\nEnglish: 4\nHistory: 5\n\n");
}

TEST(GroupTests, CreateGroup) {
    Group g = Group{};
    
    std::stringstream ss;
    ss << g;
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}

TEST(GroupTests, SetGroupNumber) {
     Group g = Group{};
     g.setGroup(2);
     EXPECT_EQ(g.getGroupNumber(), 2);
}

// TEST(GroupTests, addStudentToGroup)
// {
//     Student stud1 = Student{};
//     std::string data1 = "Ivanov\nFree\nAlgebra 4\nGeometry 3\nPhysics 2\nEnglish 4\nHistory 5\n";
//     std::stringstream ss1(data1);
//     ss1 >> stud1;

//     Student stud2 = Student{};
//     std::string data2 = "Petrov\nPaid\nAlgebra 5\nGeometry 5\nPhysics 4\nEnglish 3\nHistory 3\n";
//     std::stringstream ss2(data2);
//     ss2 >> stud2;


//     Group g = Group{};
//     g.setGroup(3);
//     g.fillGroupStudents(stud1);
//     g.fillGroupStudents(stud2);

//     std::stringstream ss3;
//     ss3 << g;
//     ASSERT_EQ(ss3.str(), "3\nPetrov\nPaid\nAlgebra: 5\nGeometry: 5\nPhysics: 4\nEnglish: 3\nHistory: 3\n\n\n3\nIvanov\nFree\nAlgebra: 4\nGeometry: 3\nPhysics: 2\nEnglish: 4\nHistory: 5\n\n\n");
// }