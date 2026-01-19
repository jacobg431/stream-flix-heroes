#include "catch_amalgamated.hpp"

#include "../Models/User.hpp"
#include "../Models/UserReview.hpp"
#include "../Models/WatchHistory.hpp"
#include "../Models/Movie.hpp"

TEST_CASE("User model getName returns correct name")
{
    const std::string inputName = "Alice"; 
    const std::string expectedName = "Alice"; 

    User user(inputName, 1, "alice@example.com", "premium");

    REQUIRE(user.getName() == expectedName);
}

TEST_CASE("User model getId returns correct userId")
{
    const int inputId = 42; 
    const int expectedId = 42;

    User user("Alice", inputId, "alice@example.com", "premium");

    REQUIRE(user.getId() == expectedId);
}

TEST_CASE("User model getEmail returns correct email")
{
    const std::string inputEmail = "alice@example.com";
    const std::string expectedEmail = "alice@example.com";

    User user("Alice", 1, inputEmail, "premium");

    REQUIRE(user.getEmail() == expectedEmail);
}

TEST_CASE("User model getSubscriptionType returns correct subscription type")
{
    const std::string inputSubscriptionType = "premium";
    const std::string expectedSubscriptionType = "premium"; 

    User user("Alice", 1, "alice@example.com", inputSubscriptionType);
    REQUIRE(user.getSubscriptionType() == expectedSubscriptionType);
}



TEST_CASE("UserReview model getUserId returns correct userId")
{
    const int inputUserId = 1;
    const int expectedUserId = 1;
    const std::chrono::system_clock::time_point inputReviewDate = std::chrono::system_clock::now();

    UserReview review(inputUserId, 101, 202, 4.5, "Great movie!", inputReviewDate);

    REQUIRE(review.getUserId() == expectedUserId);
}

TEST_CASE("UserReview model getReviewId returns correct reviewId")
{
    const int inputReviewId = 101;
    const int expectedReviewId = 101;

    UserReview review(1, inputReviewId, 202, 4.5, "Great movie!", std::chrono::system_clock::now());

    REQUIRE(review.getReviewId() == expectedReviewId);
}

TEST_CASE("UserReview model getMovieId returns correct movieId")
{
    const int inputMovieId = 202;
    const int expectedMovieId = 202;

    UserReview review(1, 101, inputMovieId, 4.5, "Great movie!", std::chrono::system_clock::now());

    REQUIRE(review.getMovieId() == expectedMovieId);
}

TEST_CASE("UserReview model getRating returns correct rating")
{
    const double inputRating = 4.5;
    const double expectedRating = 4.5;

    UserReview review(1, 101, 202, inputRating, "Great movie!", std::chrono::system_clock::now());

    REQUIRE(review.getRating() == expectedRating);
}

TEST_CASE("UserReview model getComment returns correct comment")
{
    const std::string inputComment = "Great movie!";
    const std::string expectedComment = "Great movie!";

    UserReview review(1, 101, 202, 4.5, inputComment, std::chrono::system_clock::now());

    REQUIRE(review.getComment() == expectedComment);
}

TEST_CASE("UserReview model getReviewDate returns correct review date")
{
    const std::chrono::system_clock::time_point inputReviewDate = std::chrono::system_clock::now();

    UserReview review(1, 101, 202, 4.5, "Great movie!", inputReviewDate);

    REQUIRE(review.getReviewDate() == inputReviewDate);
}

TEST_CASE("WatchHistory moodel returns correct user ID value")
{
    const int inputUserId = 1;
    const int expectedUserId = 1;

    WatchHistory history(inputUserId, 301, 401, std::chrono::system_clock::now(), 75.0);

    REQUIRE(history.getUserId() == expectedUserId);
}

TEST_CASE("WatchHistory model returns correct watch ID value")
{
    const int inputWatchId = 301;
    const int expectedWatchId = 301;

    WatchHistory history(1, inputWatchId, 401, std::chrono::system_clock::now(), 75.0);

    REQUIRE(history.getWatchId() == expectedWatchId);
}

TEST_CASE("WatchHistory model returns correct movie ID value")
{
    const int inputMovieId = 401;
    const int expectedMovieId = 401;

    WatchHistory history(1, 301, inputMovieId, std::chrono::system_clock::now(), 75.0);

    REQUIRE(history.getMovieId() == expectedMovieId);
}

TEST_CASE("WatchHistory model returns correct watch date value")
{
    const std::chrono::system_clock::time_point inputWatchDate = std::chrono::system_clock::now();

    WatchHistory history(1, 301, 401, inputWatchDate, 75.0);

    REQUIRE(history.getWatchDate() == inputWatchDate);
}

TEST_CASE("WatchHistory model returns correct completion percentage value")
{
    const double inputCompletionPercentage = 75.0;
    const double expectedCompletionPercentage = 75.0;

    WatchHistory history(1, 301, 401, std::chrono::system_clock::now(), inputCompletionPercentage);

    REQUIRE(history.getCompletionPercentage() == expectedCompletionPercentage);
}


TEST_CASE("Movie model getTitle returns correct title")
{
    const std::string inputTitle = "The Matrix";
    const std::string expectedTitle = "The Matrix";
    Movie movie(inputTitle, 1, "Sci-Fi", 1999, 8.7, 136);

    REQUIRE(movie.getTitle() == expectedTitle);
}

TEST_CASE("Movie model getId returns correct id")
{
    const int inputId = 1;
    const int expectedId = 1;
    Movie movie("The Matrix", inputId, "Sci-Fi", 1999, 8.7, 136);

    REQUIRE(movie.getId() == expectedId);
}

TEST_CASE("Movie model getGenre returns correct genre")
{
    const std::string inputGenre = "Sci-Fi";
    const std::string expectedGenre = "Sci-Fi";
    Movie movie("The Matrix", 1, inputGenre, 1999, 8.7, 136);

    REQUIRE(movie.getGenre() == expectedGenre);
}

TEST_CASE("Movie model getReleaseYear returns correct release year")
{
    const int inputReleaseYear = 1999;
    const int expectedReleaseYear = 1999;
    Movie movie("The Matrix", 1, "Sci-Fi", inputReleaseYear, 8.7, 136);

    REQUIRE(movie.getReleaseYear() == expectedReleaseYear);
}

TEST_CASE("Movie model getRating returns correct rating")
{
    const double inputRating = 8.7;
    const double expectedRating = 8.7;
    Movie movie("The Matrix", 1, "Sci-Fi", 1999, inputRating, 136);

    REQUIRE(movie.getRating() == expectedRating);
}

TEST_CASE("Movie model getDuration returns correct duration")
{
    const int inputDuration = 136;
    const int expectedDuration = 136;
    Movie movie("The Matrix", 1, "Sci-Fi", 1999, 8.7, inputDuration);

    REQUIRE(movie.getDuration() == expectedDuration);
}