#ifndef _music_sync_test_TEST_H
#define _music_sync_test_TEST_H

#include <cppunit/Test.h> 

class music_sync_testTest : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(music_sync_testTest);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();    

    // agregate test functions
    void execute();
    void execute(int argc, char* argv[]);

protected:
    
private:
    int m_argc;
    char* m_argv[10];
    
};

#endif