var cityName;
        
function getWeather(){
    // clear previous weather data
    $('.weatherResponse').html('');
        
    cityName = $('#cityName').val();
    $.getJSON('https://api.openweathermap.org/data/2.5/weather?appid=1bacbd261e64f80aa7af050c51580c6f&units=imperial&q='+cityName, giveWeather, 'jsonp');
}
        
function giveWeather(data) {
    var location = data.name;
    var description = data.weather[0].description;
    var temp = data.main.temp;
    var temphi = data.main.temp_max;
    var templo = data.main.temp_min;
    document.getElementById("weatherOutput").innerHTML = "In " + location + " it is currently " + temp + " degrees with " + description + " with a high of " + temphi + " and a low of " + templo + ".";

}    