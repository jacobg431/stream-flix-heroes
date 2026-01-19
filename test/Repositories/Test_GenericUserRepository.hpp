#include <catch2/catch_test_macros.hpp>
#include "../../src/Repositories/GenericUserRepository.hpp"
#include "../../src/Database/DbConnection.hpp"

struct DbFixture
{
    DbConnection test_db{"StreamFlix_TestDB", "test_user", "test_password"};

    DbFixture()
    {
        test_db.ExecCommand("BEGIN;");
    }

    ~DbFixture()
    {
        // rollback even if the test fails
        test_db.ExecCommand("ROLLBACK;");
    }
};

TEST_CASE_METHOD(DbFixture, "GenericUserRepository::selectUserById selects the correct user", "[Repository]")
{
    // Arrange
    GenericUserRepository userTestRepository(test_db);
    User expectedUser = User("Alice", "Johnson", 1, "alice.johnson@example.com", "Premium");

    // Act
    User actualUser = userTestRepository.selectUserById(1);
    // Assert
    REQUIRE(actualUser == expectedUser);
}

TEST_CASE_METHOD(DbFixture, "GenericUserRepository::selectUserByName selects the correct user", "[Repository]")
{
    // Arrange
    GenericUserRepository userTestRepository(test_db);
    User expectedUser = User("Alice", "Johnson", 1, "alice.johnson@example.com", "Premium");

    // Act
    User retrievedUser = userTestRepository.selectUserByName("Alice", "Johnson");
    // Assert
    REQUIRE(retrievedUser == expectedUser);
}

TEST_CASE_METHOD(DbFixture, "GenericUserRepository::selectMultipleUsers retrieves the correct number of users", "[Repository]")
{
    // Arrange
    GenericUserRepository userTestRepository(test_db);
    int expectedNumUsers = 5;
    int offset = 0;

    // Act
    std::vector<User> users = userTestRepository.selectMultipleUsers(expectedNumUsers, offset);
    int actualNumUsers = users.size();

    // Assert
    REQUIRE(actualNumUsers == expectedNumUsers);
}

TEST_CASE_METHOD(DbFixture, "GenericUserRepository::insertUser inserts a new user successfully", "[Repository]")
{
    // Arrange
    GenericUserRepository userTestRepository(test_db);
    User insertedUser = User("tester", "lester", 42, "tester@lester.com", "Premium");

    // Act
    userTestRepository.insertUser(insertedUser);
    User retrievedUser = userTestRepository.selectUserById(42);

    // Assert
    REQUIRE(retrievedUser == insertedUser);
}

TEST_CASE_METHOD(DbFixture, "GenericUserRepository::updateUser updates an existing user successfully", "[Repository]")
{
    // Arrange
    GenericUserRepository userTestRepository(test_db);
    User originalUser = User("Alice", "Johnson", 1, "alice.johnson@example.com", "Premium");

    // NOTE:
    //
    // CHANGE == OPERATOR FOR USERS?

    // Act
    User expectedUser = User("Bob", "Johnson", 3, "bob@johnson.com", "Basic");
    userTestRepository.updateUser(expectedUser);
    User actualUser = userTestRepository.selectUserById(3);

    // Assert
    REQUIRE(actualUser == expectedUser);
}

TEST_CASE_METHOD(DbFixture, "GenericUserRepository::countUsers returns the correct user count", "[Repository]")
{
    // Arrange
    GenericUserRepository userTestRepository(test_db);
    int expectedUserCount = 30;

    // Act
    int actualUserCount = userTestRepository.countUsers();

    // Assert
    REQUIRE(actualUserCount == expectedUserCount);
}
