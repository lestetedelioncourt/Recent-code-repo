==> ./3-2-ktor-jackson/run_docker.sh <==
#!/usr/bin/bash

cd $(dirname $0)

docker run -i --network host loadimpact/k6 run - <script.js

==> ./4-2-ktor-data-posted-to-endpoint/script/curl_file.sh <==
#!/usr/bin/bash

cd $(dirname $0)
/usr/bin/curl -v -F "file=@myfile.txt" "localhost:8080/file"
==> ./5-1-mongodb/scripts/replace/curl_replaceship.sh <==
#!/usr/bin/bash

/usr/bin/curl -X POST -v -H "Content-Type: application/json" -d '{"id":"61afc02543dea430b9a323d3", "name":"round", "fuel":"20.0" }' localhost:8080/replace
==> ./6-4-k6-performance-testing/scripts/run_docker.sh <==
#!/usr/bin/bash

cd $(dirname $0)

docker run -i --network host loadimpact/k6 run - <script.js

==> ./bookstore/scripts/performance/run_docker.sh <==
#!/usr/bin/bash

cd $(dirname $0)

docker run -i --network host loadimpact/k6 run - <script.js

==> ./bookstore/scripts/post_book.sh <==
#!/usr/bin/bash

/usr/bin/curl -H 'Content-Type: application/json'  -u "shopper1:password" -X POST -d '{"id":"102", "title":"How to use PiOS v2", "author":"Mr LinuxHappy", "price":"169.8"}' http://localhost:8080/api/book/102
==> ./bookstore/scripts/put_book.sh <==
#!/usr/bin/bash

/usr/bin/curl -v -H 'Content-Type: application/json' -u "shopper1:password" -X PUT -d '{"id":"102", "title":"How to use PiOS", "author":"Mr LinuxHappy", "price":"169.8"}' http://localhost:8080/api/book
==> ./jquery/htmlToKotlinDSL.sh <==
#!/usr/bin/bash

VAR1="$1"
VAR2="$2"
VAR3="$3"

sed -i "s/\/>/\n\t\t\t\t\t}/;${VAR1},${VAR2}s/\([\t\ ]\{2\}\)\([A-Za-z0-9][^$]*\)$/\1\t+\"\2\"/;s/[a-z]\+\=/\n\t\t\t\t\t\t&/g;${VAR1},${VAR2}s/\(type\=\)\"\([a-z]\+\)\"/\1InputType.\2/;${VAR1},${VAR2}s/class\=\([^$]*\)/this.attributes.put(\"class\", \1)/;s/<br\/>/br{ }/g;s/[\ \t]<\/[a-z0-9]\+>/}/;s/<\/[a-z0-9]\+>/\n\t\t\t\t\t}/;s/<\([a-z0-9]\+\)/\1 {/;s/\">/\"/;${VAR1},${VAR2}s/[><]//g;s/}\([a-z]\)/}\n\t\t\t\t\t\1/;s/textarea/textArea/;s/checkbox/checkBox/" ${PWD}/${VAR3}

#sed -i "28,134s/\(type\=\)\"\([a-z]\+\)\"/\1InputType.\2/;28,164s/class\=\([^$]*\)/this.attributes.put(\"class\", \1)/;s/<br\/>/br{ }/g;s/<\/[a-z]\+>/}/;s/<\([a-z]\+\)/\1 {/;s/\">/\"/;28,53s/\([\t\ ]\{2\}\)\([A-Z][^$]*\)$/\1\t+\"\2\"/;28,53s/[><]//g" src/Application.kt

==> ./jquery/htmlToKotlinDSL2.sh <==
#!/usr/bin/bash

VAR1="$1"
VAR2="$2"
VAR3="$3"

sed -i "${VAR1},${VAR2}s/\/>/\n\t\t\t\t\t}/;${VAR1},${VAR2}s/\([\t\ ]\{2\}\)\([A-Za-z0-9][^$]*\)$/\1\t+\"\2\"/;${VAR1},${VAR2}s/[a-z]\+\=/\n\t\t\t\t\t\t&/g;${VAR1},${VAR2}s/\(type\=\)\"\([a-z]\+\)\"/\1InputType.\2/;${VAR1},${VAR2}s/class\=\([^$]*\)/this.attributes.put(\"class\", \1)/;${VAR1},${VAR2}s/<br\/>/br{ }/g;${VAR1},${VAR2}s/[\ \t]<\/[a-z0-9]\+>/}/;${VAR1},${VAR2}s/<\/[a-z0-9]\+>/\n\t\t\t\t\t}/;${VAR1},${VAR2}s/<\([a-z0-9]\+\)/\1 {/;${VAR1},${VAR2}s/\">/\"/;${VAR1},${VAR2}s/[><]//g;${VAR1},${VAR2}s/}\([a-z]\)/}\n\t\t\t\t\t\1/;${VAR1},${VAR2}s/textarea/textArea/;${VAR1},${VAR2}s/checkbox/checkBox/" ${PWD}/${VAR3}

#sed -i "28,134s/\(type\=\)\"\([a-z]\+\)\"/\1InputType.\2/;28,164s/class\=\([^$]*\)/this.attributes.put(\"class\", \1)/;s/<br\/>/br{ }/g;s/<\/[a-z]\+>/}/;s/<\([a-z]\+\)/\1 {/;s/\">/\"/;28,53s/\([\t\ ]\{2\}\)\([A-Z][^$]*\)$/\1\t+\"\2\"/;28,53s/[><]//g" src/Application.kt

==> ./ktor-routes/script/echo.sh <==
#!/usr/bin/bash

echo "hello"