#include <vector>
#include <string>
#include "User.hpp"
#include "WatchHistory.hpp"  
#include "UserSubscriptionType.hpp"
#include "UserReview.hpp"
#include "Movie.hpp"

class DatabaseRepository {
private:
    

public:
    User getUserById(int id); 
    User getUserByName(std::string name); 
    std::vector<User> getMultipleUsers(int amount, int offset);
    void addUser(User user);
    void updateUser(User& user);
    std::vector<int> getUserAmountPerSubscriptionType(); 
    std::vector<Movie> getMostWatchedMovies(int amount);
    std::string getMostPopularGenre(User user); 


};







