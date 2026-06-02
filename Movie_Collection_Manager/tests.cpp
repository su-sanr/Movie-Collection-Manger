#include "tests.h"
#include "json_repository.h"
#include "controller.h"
#include "concrete_filters.h"
#include <cassert>
#include <iostream>

void runAllTests() {
    std::cout << "Starting automated tests...\n";

    // 1. Setup a fresh test repository
    JsonMovieRepository repo("test_db.json");
    Controller ctrl(repo);

    // Clear any leftover data from previous test runs
    auto initialMovies = ctrl.getAllMovies();
    for (const auto& m : initialMovies) {
        ctrl.removeMovie(m.getTitle());
    }

    // 2. Test Add
    ctrl.addMovie(Movie("Test Movie 1", "Action", 2020, "url1"));
    ctrl.addMovie(Movie("Test Movie 2", "Comedy", 2021, "url2"));
    assert(ctrl.getAllMovies().size() == 2); // Verify both were added

    // 3. Test Update
    ctrl.updateMovie("Test Movie 1", Movie("Test Movie 1", "Action", 2022, "url1_new"));
    assert(ctrl.getAllMovies()[0].getYear() == 2022); // Verify the year changed

    // 4. Test Remove
    ctrl.removeMovie("Test Movie 2");
    assert(ctrl.getAllMovies().size() == 1); // Verify it was deleted

    // 5. Test Undo/Redo (The Command Pattern)
    ctrl.undo(); // Undoes the removal, bringing Test Movie 2 back
    assert(ctrl.getAllMovies().size() == 2);

    ctrl.undo(); // Undoes the update, reverting Test Movie 1 to 2020
    assert(ctrl.getAllMovies()[0].getYear() == 2020);

    ctrl.redo(); // Redoes the update, putting Test Movie 1 back to 2022
    assert(ctrl.getAllMovies()[0].getYear() == 2022);

    // 6. Test Filtering (The Strategy Pattern)
    GenreFilter actionFilter("Action");
    auto filtered = ctrl.filterMovies(actionFilter);
    assert(filtered.size() == 1);
    assert(filtered[0].getTitle() == "Test Movie 1");

    std::cout << "All tests passed successfully!\n";
}