==> ./3-6-ktor-location-request-parameter/script/curl_list_request_params.bat <==
curl "http://localhost:8080/book/flowers/list?sortby=author,releasedate&asc=1"
==> ./3-7-ktor-default-headers/script/curl_headers.bat <==
curl -v -H "testheader: value123" "http://localhost:8080/"
==> ./4-1-ktor-status-pages/scripts/first.bat <==
curl -v http://localhost:8080/first
==> ./4-1-ktor-status-pages/scripts/second.bat <==
curl -v http://localhost:8080/second
==> ./4-1-ktor-status-pages/scripts/third.bat <==
curl -v http://localhost:8080/third
==> ./4-1-ktor-status-pages/scripts/url_not_found.bat <==
curl -v http://localhost:8080/url_not_found
==> ./4-2-ktor-data-posted-to-endpoint/script/curl_file.bat <==
curl -v -F "file=@myfile.txt" "localhost:8080/file"
==> ./4-2-ktor-data-posted-to-endpoint/script/curl_formparameters.bat <==
curl -F "username=mike" -F "password=mypassword" -F "role=admin" "localhost:8080/form"
==> ./4-2-ktor-data-posted-to-endpoint/script/curl_text.bat <==
curl -d "This is some data that we post to the text endpoint" "localhost:8080/text"
==> ./4-3-basic-authentication/scripts/curl_root.bat <==
curl localhost:8080
==> ./4-3-basic-authentication/scripts/curl_trend.bat <==
curl -v -u "user:userabc123" "localhost:8080/trendycolor/nextmonth"
curl -v -u "user:userabc123" "localhost:8080/trendycolor/nextyear"
curl -v -u "user:userabc1223" "localhost:8080/trendycolor/nextyear"
==> ./4-3-basic-authentication/scripts/curl_trend.bat <==
curl -v -u "user:userabc123" "localhost:8080/trendycolor/nextmonth"
curl -v -u "user:userabc123" "localhost:8080/trendycolor/nextyear"
curl -v -u "user:userabc1223" "localhost:8080/trendycolor/nextyear"
==> ./4-3-basic-authentication/scripts/curl_trend.bat <==
curl -v -u "user:userabc123" "localhost:8080/trendycolor/nextmonth"
curl -v -u "user:userabc123" "localhost:8080/trendycolor/nextyear"
curl -v -u "user:userabc1223" "localhost:8080/trendycolor/nextyear"
==> ./4-3-basic-authentication/scripts/curl_weather.bat <==
curl -v localhost:8080/secret/weather
curl -u "mike:password" -v localhost:8080/secret/weather

REM "curl -u" argument used to specify username/password
==> ./4-3-basic-authentication/scripts/curl_weather.bat <==
curl -v localhost:8080/secret/weather
curl -u "mike:password" -v localhost:8080/secret/weather

REM "curl -u" argument used to specify username/password
==> ./4-3-basic-authentication/scripts/curl_weather.bat <==
curl -v localhost:8080/secret/weather
curl -u "mike:password" -v localhost:8080/secret/weather

REM "curl -u" argument used to specify username/password
==> ./4-4-ktor-interceptor/scripts/curl_root.bat <==
curl -v localhost:8080
==> ./4-5-call-logging/scripts/curl_calllogging.bat <==
curl -v localhost:8080/calllogging/test
==> ./4-5-call-logging/scripts/curl_root.bat <==
curl -v localhost:8080/
==> ./5-1-mongodb/scripts/find/curl_allships.bat <==
curl -v localhost:8080/allships
==> ./5-1-mongodb/scripts/find/curl_oneship.bat <==
curl -v localhost:8080/oneship/61afbaaf150b2810e016c2d9
==> ./5-1-mongodb/scripts/find/curl_shipswithfuel.bat <==
curl localhost:8080/ships?fuelmin=30.0
==> ./5-1-mongodb/scripts/find/curl_sortedships.bat <==
curl "localhost:8080/sortedships?page=1&pagesize=3"
==> ./5-1-mongodb/scripts/update/curl_update.bat <==
curl -v -X POST localhost:8080/fuelup/61afbaaf150b2810e016c2d9
==> ./bookstore/scripts/curl_sortedbooks.bat <==
curl -u "shopper1:password" "http://localhost:8080/api/book/list?sortby=title&asc=true"
==> ./bookstore/scripts/delete_books.bat <==
curl -X DELETE -u "admin:password" "localhost:8080/api/book/61b230ef99a9dc3fbaa02d9b"
==> ./bookstore/scripts/get_books.bat <==
curl -u "shopper1:password" localhost:8080/api/book/all
==> ./bookstore/scripts/new_book.bat <==
curl -u "shopper1:password" -H 'Content-Type: application/json' -X PUT -d '{"id":"103", "title":"How to use MacOS", "author":"Mr LinuxHappy", "price":"169.8"}' http://localhost:8080/api/book/list
==> ./ktor-content-negotiation/script/curl_json.bat <==
curl -H "Accept: application/json" "http://localhost:8080/spaceship"
==> ./ktor-content-negotiation/script/curl_xml.bat <==
curl -H "Accept: application/xml" "http://localhost:8080/spaceship"
==> ./ktor-routes/script/curl_get_europe.bat <==
curl -H "systemtoken: weathersystem" -G http://localhost:8080/weather/europe?name=mike
curl -X POST http://localhost:8080/weather/europe
curl -G http://localhost:8080/weather/usa
curl -X POST http://localhost:8080/weather/usa
==> ./ktor-routes/script/curl_get_europe.bat <==
curl -H "systemtoken: weathersystem" -G http://localhost:8080/weather/europe?name=mike
curl -X POST http://localhost:8080/weather/europe
curl -G http://localhost:8080/weather/usa
curl -X POST http://localhost:8080/weather/usa
==> ./ktor-routes/script/curl_get_europe.bat <==
curl -H "systemtoken: weathersystem" -G http://localhost:8080/weather/europe?name=mike
curl -X POST http://localhost:8080/weather/europe
curl -G http://localhost:8080/weather/usa
curl -X POST http://localhost:8080/weather/usa
==> ./ktor-routes/script/curl_get_europe.bat <==
curl -H "systemtoken: weathersystem" -G http://localhost:8080/weather/europe?name=mike
curl -X POST http://localhost:8080/weather/europe
curl -G http://localhost:8080/weather/usa
curl -X POST http://localhost:8080/weather/usa
