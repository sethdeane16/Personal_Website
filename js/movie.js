var movieName;
        
function getMovie() {
    // clear previous movie data
    $('.movieResponse').html('');
    
    movieName = $('#movieName').val();
    $.getJSON('https://api.themoviedb.org/3/search/movie?query=' + movieName + '&api_key=e04363b6003ab8f85d77d8c8e47d2d71&language=en-US', giveMovie);
}
        
function giveMovie(data) {
    var title = data.results[0].title;
    var description = data.results[0].overview;
    document.getElementById("movieTitle").innerHTML = title;
    document.getElementById("movieDescription").innerHTML = description;
}  