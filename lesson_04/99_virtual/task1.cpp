#include <stdio.h>

class Test {
 public:
  virtual void init() {
    printf("Test::init()\n");
  }
  Test() {
    printf("Test::Test()\n");
  }
  /*virtual*/ ~Test() {
    printf("Test::~Test()\n");
  }
};

class Test2 : public Test {
 public:
  virtual void init() {
    printf("Test2::init()\n");
  }
  Test2() {
    printf("Test2::Test2()\n");
  }
  /*virtual*/~Test2() {
    printf("Test2::~Test2()\n");
  }
};

int main (int argc, char** argp) {
  {
    printf("1\n");
    Test* test = new Test2();
    test->init();
    delete test;
  }
  {
    printf("2\n");
    Test test = Test2();
    test.init();
  }
  return 0;
}