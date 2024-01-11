#Rishikesh S
#Date: 9/01/2024
#Weather Report using open weather API

import requests

API_KEY = "20c2e75c517749f936cb806b3cbc573b"

city = input("Enter City Name:")

url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}"

response = requests.get(url)


if response.status_code == 200:
    data = response.json()
    temperature = data["main"]["temp"] - 273.15
    description = data["weather"][0]["description"]
    wind_speed = data["wind"]["speed"]
    weather = data["weather"][0]["main"]
    print(f"Weather in {city}:")
    print(f"Temperature: {temperature:.2f} °C")
    print(f"Description: {description}")
    print(f"Wind Speed: {wind_speed} m/s")
    print(f"Weather: {weather}")
else:
    print(f"Failed to retrieve weather data for {city}. Please check the city name or API key.")
