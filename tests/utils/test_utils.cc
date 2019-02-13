#include <gtest/gtest.h>

GTEST_API_ int
main(int argc, char **argv)
{
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

extern "C" {
  #include <lunasort/utils/file.h>
}

class Utils: public testing::Test
{
};

TEST_F(Utils, File)
{
    size_t len = 0;
    char *buf = filetobuf("./tests/utils/test.txt", &len);
    EXPECT_EQ(len, sizeof("Foo Bar") - 1);
    EXPECT_TRUE(strncmp("Foo Bar", buf, len) == 0);
    free(buf);
}