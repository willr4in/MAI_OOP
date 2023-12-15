#include <gtest/gtest.h>
#include "../include/containers/vector.hpp"
#include "../src/containers/vector.cpp"
#include "../include/figures/Square.hpp"


TEST(constructor_test, default_constructor_test) {
    vector<Figure*> test_1; 

    EXPECT_EQ(test_1.capacity(), 1);
    EXPECT_EQ(test_1.size(), 0);
}

TEST(constructor_test, initializer_constructor_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);
    Square*  square_ptr6 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5), static_cast<Figure*>(square_ptr6)};

    EXPECT_EQ(test_1.capacity(), 6);
    EXPECT_EQ(test_1.size(), 6);
}

TEST(constructor_test, copy_constructor_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);
    Square*  square_ptr6 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5), static_cast<Figure*>(square_ptr6)};

    vector<Figure*> test_2 (test_1);

    EXPECT_EQ(test_1.size(), 6);
    EXPECT_EQ(test_2.capacity(), 6);

    for (size_t i = 0; i != test_1.size(); ++i) {
        EXPECT_EQ(test_1[i], test_2[i]);
    }

    EXPECT_TRUE(test_1 == test_2);
}

TEST(assigment_operator_test, copy_assigment_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);
    Square*  square_ptr6 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5), static_cast<Figure*>(square_ptr6)};

    vector<Figure*> test_2 (test_1);

    EXPECT_EQ(test_1.size(), 6);
    EXPECT_EQ(test_2.capacity(), 6);

    for (size_t i = 0; i != test_1.size(); ++i) {
        EXPECT_EQ(test_1[i], test_2[i]);
    }

    EXPECT_TRUE(test_1 == test_2);
}

TEST(reserve_test, empty_vector) {
    vector<Figure*> test_1;
    size_t capacity = 100;

    test_1.reserve(capacity); 

    EXPECT_EQ(test_1.capacity(), capacity);
}

TEST(resize_test, resize_vector) {
    vector<Figure*> test_1;
    size_t size = 10;
    Square*  square_ptr1 = new Square(5);
    test_1.resize(size, static_cast<Figure*>(square_ptr1)); 

    EXPECT_EQ(test_1.capacity(), size);
    EXPECT_EQ(test_1.size(), size);

    for (size_t i = 0; i < test_1.size(); ++i) {
        EXPECT_EQ(test_1[i], static_cast<Figure*>(square_ptr1));
    }
}

TEST(push_back_test, push_back_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5)};

    size_t size = test_1.size();

    Square*  square_ptr6 = new Square(5);
    test_1.push_back(static_cast<Figure*>(square_ptr6));

    EXPECT_EQ(test_1.size(), size + 1);
    EXPECT_EQ(test_1[test_1.size() - 1], static_cast<Figure*>(square_ptr6));
}

TEST(pop_back_test, pop_back_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5)};

    size_t size = test_1.size();

    test_1.pop_back();

    EXPECT_EQ(test_1.size(), size - 1);
    EXPECT_EQ(test_1[test_1.size() - 1], static_cast<Figure*>(square_ptr4));
}

TEST(erase_test, erase_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);
    Square*  square_ptr6 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5), static_cast<Figure*>(square_ptr6)};

    size_t size = test_1.size();

    test_1.erase(2);
    EXPECT_EQ(test_1[2], static_cast<Figure*>(square_ptr4));
    EXPECT_EQ(test_1.size(), size - 1);
}

TEST(size_test, size_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);
    Square*  square_ptr6 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5), static_cast<Figure*>(square_ptr6)};

    EXPECT_EQ(test_1.size(), 6);
}

TEST(capacity_test, capacity_test) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);
    Square*  square_ptr6 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5), static_cast<Figure*>(square_ptr6)};

    EXPECT_EQ(test_1.capacity(), 6);
}

TEST(emty_test, true_return) {
    vector<Figure*> test_1;

    EXPECT_TRUE(test_1.empty());
}

TEST(empty_test, false_return) {
    Square*  square_ptr1 = new Square(5);
    Square*  square_ptr2 = new Square(5);
    Square*  square_ptr3 = new Square(5);
    Square*  square_ptr4 = new Square(5);
    Square*  square_ptr5 = new Square(5);
    Square*  square_ptr6 = new Square(5);

    vector<Figure*> test_1 {static_cast<Figure*>(square_ptr1), static_cast<Figure*>(square_ptr2), static_cast<Figure*>(square_ptr3),
                            static_cast<Figure*>(square_ptr4), static_cast<Figure*>(square_ptr5), static_cast<Figure*>(square_ptr6)};

    EXPECT_FALSE(test_1.empty());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
