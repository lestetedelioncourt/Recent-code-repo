==> ./001_javascript/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        /*get("/") {
            call.respondText("HELLO WORLD!", contentType = ContentType.Text.Plain)
        }*/

        get("/") {
            call.respondHtml {
                head{
                }
                body {
                    script(type = "text/javascript") {
                        +"""
		| window.onload = function () {
		|	// getElementById(String type, EventListener listner, (Boolean useCapture))  
		|	document.getElementById('button1').addEventListener('click', clickHandler, false)
		| };
		|
		| function clickHandler() 
		| {
		|	alert('jQuery Tutorial');
		| }""".trimMargin("|")
                    }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
    }
}

==> ./001_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: 	+"Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)"

@Suppress("unused") // 	+"Referenced in application.conf"
@kotlin.jvm.JvmOverloads
fun 	+"Application.module(testing: Boolean = false) {"
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    script(type = "text/javascript") {
                        + """ jQuery(document).ready(function(){
		                    |           jQuery('#button1').click(function() {
		                    |		        alert('jQuery 	+"Tutorial');"
		                    |	        });
		                    |       });""".trimMargin("|")
                    }
                    input(type = 	+"InputType.button) {"
                        id = "button1"
                        value = "Click me"
                    }
                }
            }
        }

        // 	+"Static feature. Try to access `/static/ktor_logo.svg"
        static("/") {
            resources("")
        }
    }
}

==> ./001_jquerya/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    script(src = "myscript.js") { }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./001_jqueryb/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    script(type = "text/javascript") {
                        + """ $().ready(function() {
		                    |   $('#button1').click(function() {
		                    |       alert('jQuery Tutorial');
		                    |   });
		                    |});""".trimMargin("|")
                    }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./001_jqueryc/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    script(type = "text/javascript") {
                        + """ $(function() {
		                    |   $('#button1').click(function() {
		                    |       alert('jQuery Tutorial');
		                    |   });
		                    |});""".trimMargin("|")
                    }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./002_jquery/001_jqueryb/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    script(type = "text/javascript") {
                        + """ $().ready(function() {
		                    |   $('#button1').click(function() {
		                    |       alert('jQuery Tutorial');
		                    |   });
		                    |});""".trimMargin("|")
                    }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./002_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    script(src = "myscript.js") {}
                    /*script(type = "text/javascript") {
                        + """$(window).on('load', function() {
			                |    alert('Window loaded');
			                |    $('#div1').html('Height = ' + $('#img1').height());
                            |    $('#p1').html('Width = ' + ${'$'}('#img1').width());
                            |    $('#div1').append($('#p1')); 			
		                    |});
		                    |
		                    |$(document).ready(function(){
			                |   alert('DOM loaded and ready');
		                    |});""".trimMargin("|")
                    }*/
                    div {
                       id =  "div1"
                    }
                    p {
                        id = "p1"
                    }
                    img {
                        id = "img1"
                        src = "chrysanthemum.jpg"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./003_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    table {
                        id = "table1"
                        this.attributes.put("border", "1")
                        tr {
                            td { +"C#" }
                            td { +"ASP.NET" }
                            td { +"SQL Server" }
                        }
                        tr {
	                        td { +"ADO.NET" }
	                        td { +"jQuery" }
	                        td { +"JavaScript" }
                        }
                        tr {
	                        td { +"AJAX" }
	                        td { +"CSS" }
	                        td { +"HTML" }
                        }
                        tr {
	                        td { +"VB" }
	                        td { +"Dot NET" }
	                        td { +"Visual C++" }
                        }
                        tr {
	                        td { +"Oracle" }
	                        td { +"Java" }
	                        td { +"J2EE" }
                        }
                    }
                    br { +"" }
                    table {
                        id = "table2"
                        this.attributes.put("border", "1")
                        tr {
                            td { +"Mary" }
                            td { +"Mark" }
                            td { +"Marvin" }
                        }
                        tr {
                            td { +"Jane" }
                            td { +"John" }
                            td { +"Jack" }
                        }
                    }
                    br { +"" }
                    div {
                        id = "div1"
                        +"DIV 1"
                        br {}
                        a {
                            href = "http://pragimtech.com"
                            +"Pragimtech"
                        }
                   }
                    br { +"" }
                    div {
                        id = "div2"
                        +"DIV 2"
                        br {}
                        a {
                            href = "http://google.com"
                            +"Google"
                        }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                    /*)input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }*/
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./004_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    div {
                        this.attributes.put("class", "small")
                        id="div1"
                        +"DIV 1"
                        a {
                            href="http://pragimtech.com"
                            +"Pragimtech"
                        }
                    }
                    span {
                        this.attributes.put("class", "small")
                        +"Span 1"
                    }
                    br { }
                    br { }
                    div {
                        id="div2"
                        +"DIV 2"
                        br{ }
                        div {
                            this.attributes.put("class", "small")
                            +"DIV 3"
                            div {
                                this.attributes.put("class", "big")
                                +"DIV 4"
                            }
                        }
                        br{ }
                        span {
                            this.attributes.put("class", "small")
                            +"Span 2"
                        }
                    }
                    div {
                        this.attributes.put("class", "small")
                        +"DIV 5"
                        div {
                            this.attributes.put("class", "big")
                            +"DIV 6"
                        }
                    }
                    span {
                        this.attributes.put("class", "big")
                        +"Span 3"
                    }
                    br{ }
                    p {
                        this.attributes.put("class", "big")
                        +"This is a paragraph"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./005_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    div {
                        title="div1Title"
                    	+"DIV 1"
                    }
                    div {
                        title="div2Title"
                    	+"DIV 2"
                    }
                    span {
                        title="div1Title"
                    	+"SPAN 3"
                    }
                    br { }
                    span {
                        title="span1Title"
                    	+"SPAN 1"
                    }
                    br { }
                    span {
                        title="span2Title"
                    	+"SPAN 2"
                    }
                    br { }
                    br { }
                    p {
                        title="p1Title"
                        style="background-color:red"
                    	+"This is a paragraph"
                    }
                    p {
                        title="p2Title"
                        style="background-color:green"
                    	+"This is a paragraph"
                    }
                    p {
                        style="background-color:green"
                    	+"This is a paragraph"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                    /*)input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }*/
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./006_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    div {
                        title="div1Title"
                    	+"DIV 1"
                    }
                    div {
                        title="div2Title"
                    	+"DIV 2"
                    }
                    br{ }
                    br{ }
                    p {
                        title="myTitle-Paragraph"
                        style="background-color:red"
                    	+"This is a paragraph"
                    }
                    p {
                        title="myTitleHeading"
                        style="background-color:green"
                    	+"This is a paragraph"
                    }
                    p {
                        style="background-color:green"
                    	+"This is a paragraph"
                    }
                    span {
                        title="div1Title"
                    	+"SPAN 1"
                    }
                    br{ }
                    span {
                        title="Heading as mySpan"
                    	+"SPAN 2"
                    }
                    br{ }
                    span {
                        title="span2Title"
                    	+"SPAN 3"
                    }

                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                    /*)input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }
                    input(type = InputType.button) {
                        id = "button1"
                        value = "Click me"
                    }*/
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./007_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    div {
                        title="DivTitle"
                    	+"DIV 1"
                    }
                    br{ }
                    div {
                        title="DIVTITLE"
                    	+"DIV 2"
                    }
                    br{ }
                    div {
                        title="divtitle"
                    	+"DIV 3"
                    }
                    p {
                        title="pTitle"
                    	+"Paragraph 1"
                    }
                    p {
                        title="pTITLE"
                    	+"Paragraph 2"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                    /*)input(type = 	+"InputType.button) {"
                        id = "button1"
                        value = "Click me"
                    }
                    input(type = 	+"InputType.button) {"
                        id = "button1"
                        value = "Click me"
                    }*/
                }
            }
        }

        // 	+"Static feature. Try to access `/static/ktor_logo.svg"
        static("/") {
            resources("")
        }
    }
}

==> ./008_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                	+"First Name :"
	                input {
	                    type = InputType.text
	                    value = "John"
	                }
	                br{ }
                    br{ }
					+"Last Name :"
	                input {
	                    type = InputType.text
	                    value = "Major"
	                }
	                br{ }
                    br{ }
                    +"Gender :"
	                input {
	                    type=InputType.radio
	                    name="skills"
	                    checked=true
	                    value="Male"
	                }
	                	+"Male"
	                input {
	                    type=InputType.radio
	                    name="skills"
	                    value="Female"
	                }
                    +"Female"
	                br{ }
                    br{ }
	                input {
	                    type=InputType.checkBox
	                    name="skills"
	                    checked=true
	                    value="Javascript"
	                }
					+"Javascript"
	                input {
	                    type=InputType.checkBox
	                    name="skills"
	                    checked=true
	                    value="jQuery"
	                }
                    +"JQuery"
	                input {
	                    type=InputType.checkBox
	                    name="skills"
	                    value="C#"
	                }
                    +"C#"
	                br{ }
                    br{ }
                    +"Country:"
	                select {
		                option {
		                    selected=true
		                    value="USA"
		                	+"USA"
		                }
		                option {
		                    value="India"
		                	+"India"
		                }
		                option {
		                    value="UK"
		                	+"UK"
		                }
	                }
	                br{ }
                    br{ }
                    +"Summary :"
	                br{ }
	                textArea {
						+"I am a Senior Dot Net Developer with 10 years experience"
	                }
	                br{ }
                    br{ }
	                input {
	                    type=InputType.submit
	                    value="submit"
	                }
					script(type = "text/javascript") {
						src = "myfile.js"
					}
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./009_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
	                input {
                        type=InputType.radio
                        name="skills"
                        value="Male"
	                }
                    +"Male"
	                input {
                        type=InputType.radio
                        name="skills"
                        value="Female"
	                }
                    +"Female"
	                br{ }
                    br{ }
                    input {
                        type=InputType.checkBox
                        name="skills"
                        checked=true
                        value="Javascript"
                    }
                    +"Javascript"
                    input {
                        type=InputType.checkBox
                        name="skills"
                        checked=true
                        value="jQuery"
                    }
                    +"JQuery"
                    input {
                        type=InputType.checkBox
                        name="skills"
                        value="C#"
                    }
                    +"C#"
                    br{ }
                    br{ }
	                input {
                        id="btnSubmit"
                        type=InputType.submit
                        value="submit"
	                }
	                br{ }
                    br{ }
	                div {
                        id="divResult"
	                }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./010_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                	+"Skills :"
	                input {
                        type=InputType.checkBox
                        name="skills"
                        value="Javascript"
	                }
                    +"Javascript"
	                input {
                        type=InputType.checkBox
                        name="skills"
                        value="jQuery"
	                }
                    +"JQuery"
	                input {
                        type=InputType.checkBox
                        name="skills"
                        value="C#"
	                }
                    +"C#"
	                br{ }
                    br{ }
                    +"Preferred Cities :"
	                input {
                        type=InputType.checkBox
                        name="cities"
                        value="New York"
	                }
                    +"New York"
	                input {
                        type=InputType.checkBox
                        name="cities"
                        value="New Delhi"
	                }
                    +"New Delhi"
	                input {
                        type=InputType.checkBox
                        name="cities"
                        value="London"
	                }
	                	+"London"
	                br{ }
                    br{ }
	                input {
                        id="btnGetSelectedSkills"
                        type=InputType.submit
                        value="GetSelectedSkills"
	                }
	                input {
                        id="btnGetSelectedCities"
                        type=InputType.submit
                        value="GetSelectedCities"
	                }
	                br{ }
                    br{ }
	                div {
                        id="divResult"
	                }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./011_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                	+"Skills :"
	                input {
                        type=InputType.checkBox
                        name="skills"
                        value="Javascript"
	                }
                    +"Javascript"
	                input {
                        type=InputType.checkBox
                        name="skills"
                        value="jQuery"
	                }
                    +"JQuery"
	                input {
                        type=InputType.checkBox
                        name="skills"
                        value="C#"
	                }
                    +"C#"
	                br{ }
                    br{ }
                    +"Preferred Cities :"
	                input {
                        type=InputType.checkBox
                        name="cities"
                        value="New York"
	                }
                    +"New York"
	                input {
                        type=InputType.checkBox
                        name="cities"
                        value="New Delhi"
	                }
                    +"New Delhi"
	                input {
                        type=InputType.checkBox
                        name="cities"
                        value="London"
	                }
	                	+"London"
                    br{ }
                    br{ }
	                div {
                        id="divskills"
	                }
                    br{ }
                    div {
                        id="divcities"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./012_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                	+"Skills :"
	                input {
	                    type=InputType.checkBox
	                    name="skills"
	                    value="js"
	                }
	                label {
	                    this.attributes.put("for", "cb-js")
	                    +"Javascript"
	                }
	                input {
	                    type=InputType.checkBox
	                    name="skills"
                        value="jq"
	                }
	                label {
	                    this.attributes.put("for", "cb-jq")
	                    +"JQuery"
	                }
	                input {
	                    type=InputType.checkBox
	                    name="skills"
	                    value="cs"
	                }
	                label {
	                    this.attributes.put("for", "cb-cs")
	                    +"C#"
	                }
	                br{ }
                    br{ }
	                	+"Preferred Cities :"
	                input {
	                    type=InputType.checkBox
	                    name="cities"
	                    value="ny"
	                }
	                label {
	                    this.attributes.put("for", "cb-ny")
	                    +"New York"
	                }
	                input {
	                    type=InputType.checkBox
	                    name="cities"
	                    value="nd"
	                }
	                label {
	                    this.attributes.put("for", "cb-nd")
	                    +"New Delhi"
	                }
	                input {
	                    type=InputType.checkBox
	                    name="cities"
	                    value="ln"
	                }
	                label {
	                    this.attributes.put("for", "cb-ln")
	                    +"London"
	                }
	                br{ }
                    br{ }
	                div {
	                    id="divcities"
	                }
	                br{ }
	                div {
	                    id="divskills"
	                }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./013_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    +"Country :"
                    br{ }
                    br{ }
                    select {
                        id="selectCountries"
                        multiple = true
                    option {
                        value="usa"
                    	+"United States"
                    }
                    option {
                        value="ind"
                    	+"India"
                    }
                    option {
                        value="uk"
                    	+"United Kingdom"
                    }
                    option {
                        value="ca"
                    	+"Canada"
                    }
                    option {
                        value="au"
                    	+"Australia"
                    }
                    }
                    br{ }
                    br{ }
                    div {
                        id="divResult"
                    }
                    br{ }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./014_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    table {
                        id="table1"
	                    tr {
                            td {
                                    +"First Name"
                            }
                            td {
                                input {
                                    type=InputType.text
                                    disabled=true
                                }
                            }
	                    }
	                    tr {
                            td {
                                    +"Last Name"
                            }
                            td {
                                input {
                                    type=InputType.text
                                    disabled=true
                                }
                            }
                        }
	                    tr {
                            td {
                                    +"Email"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
	                    }
	                    tr {
                            td {
                                    +"Gender"
                            }
                            td {
                                select {
                                    id="selectGender"
                                    disabled=true
                                    option {
                                        value="male"
                                        +"Male"
                                    }
                                    option {
                                        value="female"
                                        +"Female"
                                    }
                                }
                            }
	                    }
	                    tr {
                            td {
                                    +"Comments"
                            }
                            td {
                                textArea {
                                        +"I am a Senior Dot Net Developer with 10 years experience"
                                }
                            }
	                    }
                    }
                    br{ }
                    br{ }
                    input {
                        type=InputType.submit
                        value="submit"
                        disabled=true
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./015_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    ul {
                    li {
                        	+"US"
                    }
                    li {
                        	+"India"
                    }
                    li {
                        	+"UK"
                    }
                    li {
                        	+"Canada"
                    }
                    li {
                        	+"Australia"
                    }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./016_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    div {
                        id="divResult"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./018_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    style {
                        +".containerDiv"
                        +"{"
                            +"background-color:red;"
                            +"color:white;"
                            +"font-weight:bold;"
                            +"margin:3px;"
                        +"}"
                    }
                    div {
                        id="div1"
                        title="My DIV1"
                    	+"DIV 1"
                    }
                    div {
                        id="div2"
                        title="my div2"
                    	+"DIV 2"
                    }
                    div {
                        id="div3"
                    	+"DIV 3"
                    }
                    p {
                        +"Paragraph 1"
                    }
                    p {
                        +"Paragraph 2"
                    }
                    span {
                        id="resultSpan"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./019_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    style {
                        +".boldClass {"
                            +"font-weight: bold;"
                        +"}"

                        +".italicsClass {"
                            +"font-style: italic;"
                        +"}"

                        +".colorClass {"
                            +"color: green;"
                        +"}"
                    }
                    h3 {
                        +"Pragim Technologies"
                    }
                    table {
                        tr {
                            td {
                                input {
                                    id="addColor"
                                    type=InputType.button
                                    value="Add Color Class"
                                }
                            }
                            td {
                                input {
                                    id="removeColor"
                                    type=InputType.button
                                    value="Remove Color Class"
                                }
                            }
                        }
                        tr {
                            td {
                                input {
                                    id="addItalicsColor"
                                    type=InputType.button
                                    value="Add Color and Italics Classes"
                                }
                            }
                            td {
                                input {
                                    id="removeItalicsColor"
                                    type=InputType.button
                                    value="Remove Color and Italics Classes"
                                }
                            }
                        }
                        tr {
                            td {
                                input {
                                    id="addAllClasses"
                                    type=InputType.button
                                    value="Add Color, Italics & Bold Classes"
                                }
                            }
                            td {
                                input {
                                    id="removeAllClasses"
                                    type=InputType.button
                                    value="Remove All Classes"
                                }
                            }
                        }
                    }
                    p {
                        	+"Here is some paragraph text"
                    }
                    script (type="text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./020_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    style {
                        +".textBoxStyle {"
                        +"background-color: green;"
                        +"color: white;"
                    +"}"
                    }
                    table {
                        tr {
                            td {
                                    +"First Name :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                        tr {
                            td {
                                +"Last Name :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                        tr {
                            td {
                                +"Gender :"
                            }
                            td {
                                select {
                                    option {
                                        value="male"
                                        +"Male"
                                    }
                                    option {
                                        value="female"
                                        +"Female"
                                    }
                                }
                            }
                        }
                        tr {
                            td {
                                +"Email :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./021_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    ul {
                    li {
                        	+"US"
                    }
                    li {
                        	+"India"
                    }
                    li {
                        	+"UK"
                    }
                    li {
                        	+"Canada"
                    }
                    li {
                        	+"Australia"
                    }
                    }
                    div { id="divResult"
                    }
                    script (type="text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./022_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    style {
                        +".textBoxStyle {"
                        +"background-color: green;"
                        +"color: white;"
                    +"}"
                    }
                    table {
                        tr {
                            td {
                                    +"First Name :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                        tr {
                            td {
                                +"Last Name :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                        tr {
                            td {
                                +"Gender :"
                            }
                            td {
                                select {
                                    option {
                                        value="male"
                                        +"Male"
                                    }
                                    option {
                                        value="female"
                                        +"Female"
                                    }
                                }
                            }
                        }
                        tr {
                            td {
                                +"Email :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./023_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    table {
                        tr {
                            td {
                                +"First Name :"
                            }
                            td {
                                input {
                                    id="txtFirstName"
                                    type=InputType.text
                                    this.attributes.put("class", "inputRequired")
                                }
                            }
                        }
                        tr {
                            td {
                                    +"Last Name :"
                            }
                            td {
                                input {
                                    id="txtLastName"
                                    type=InputType.text
                                    this.attributes.put("class", "inputRequired")
                                }
                            }
                        }
                        tr {
                            td {
                                    +"City :"
                            }
                            td {
                                select {
                                    id="addCity"
                                    this.attributes.put("class", "inputRequired")
                                    option {
                                        value="Select"
                                        +"Select"
                                    }
                                    option {
                                        value="New York"
                                        +"New York"
                                    }
                                    option {
                                        value="New Delhi"
                                        +"New Delhi"
                                    }
                                    option {
                                        value="London"
                                        +"London"
                                    }
                                }
                            }
                        }
                        tr {
                            td {
                                    +"Favourite Color"
                            }
                            td {
                                input {
                                    id="radioRed"
                                    type=InputType.radio
                                    name="color"
                                    value="Red"
                                    this.attributes.put("class", "inputRequired")
                                }
                                    +"Red"
                                input {
                                    id="radioGreen"
                                    type=InputType.radio
                                    name="color"
                                    value="Green"
                                    this.attributes.put("class", "inputRequired")
                                }
                                    +"Green"
                                input {
                                    id="radioBlue"
                                    type=InputType.radio
                                    name="color"
                                    value="Blue"
                                    this.attributes.put("class", "inputRequired")
                                }
                                +"Blue"
                            }
                        }
                        tr {
                            td {
                                    +"Contact Method"
                            }
                            td {
                                input {
                                    type=InputType.checkBox
                                    id="chkEmail"
                                    name="skills"
                                    value="Email"
                                    this.attributes.put("class", "inputRequired")
                                }
                                    +"Email"
                                input {
                                    type=InputType.checkBox
                                    id="chkPhone"
                                    name="skills"
                                    value="Phone"
                                    this.attributes.put("class", "inputRequired")
                                }
                                    +"Phone"
                                input {
                                    type=InputType.checkBox
                                    id="chkSocial"
                                    name="skills"
                                    value="Social Media"
                                    this.attributes.put("class", "inputRequired")
                                }
                                +"Social Media"
                            }
                        }
                        tr {
                            td {
                                +"Comments"
                            }
                            td {
                            textArea {
                            }
                            }
                        }
                        tr {
                            td {
                                input {
                                    type=InputType.submit
                                    value="submit"
                                }
                            }
                            td {
                                div {
                                    id="cityResult"
                                }
                            }
                        }
                    }
                    div {
                        id="divResult"
                    }
                    script (type="text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./024_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    input {
                        id="btn1"
                        type=InputType.button
                        value="Click Me"
                        this.attributes.put("onmouseup", "whichMouseButtonClicked(event)")
                    }
                    input {
                        id="btn2"
                        type=InputType.button
                        value="No, Click Me"
                    }
                    br{ }
                    br{ }
                    div {
                        id="divResult"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./025_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style = "font-family:Arial"
                    style {
                        +".ButtonStyle"
                        +"{"
                            +"background-color: red;"
                            +"cursor: pointer;"
                            +"font-weight: bold;"
                            +"color: white;"
                        +"}"
                    }
                    h3 {
                        	+"Pragim Technologies"
                    }
                    table {
                    tr {
                    td {
                    input { 
						id="addColor" 
						type=InputType.button 
						value="Add Color Class"
                    }
                    }
                    td {
                    input { 
						id="removeColor" 
						type=InputType.button 
						value="Remove Color Class"
                    }
                    }
                    }
                    tr {
                    td {
                    input { 
						id="addItalicsColor" 
						type=InputType.button 
						value="Add Color and Italics Classes"
                    }
                    }
                    td {
                    input { 
						id="removeItalicsColor" 
						type=InputType.button 
						value="Remove Color and Italics Classes"
                    }
                    }
                    }
                    tr {
                    td {
                    input { 
						id="addAllClasses" 
						type=InputType.button 
						value="Add Color, Italics & Bold Classes"
                    }
                    }
                    td {
                    input { 
						id="removeAllClasses" 
						type=InputType.button 
						value="Remove All Classes"
                    }
                    }
                    }
                    }
                    table {
                    tr {
                    td {
                        	+"First Name :"
                    }
                    td {
                    input { 
						type=InputType.text 
						value="John"
                    }
                    }
                    }
                    tr {
                    td {
                        	+"Last Name :"
                    }
                    td {
                    input { 
						type=InputType.text 
						value="Major"
                    }
                    }
                    }
                    tr {
                    td {
                        	+"Gender :"
                    }
                    td {
                    select {
                    option { 
						value="male"
                    	+"Male"
                    }
                    option { 
						value="female"
                    	+"Female"
                    }
                    }
                    }
                    }
                    tr {
                    td {
                        	+"Email :"
                    }
                    td {
                    input { 
						type=InputType.text
                    }
                    }
                    }
                    }
                    p {
                        	+"Here is some paragraph text"
                    }
                    table {
                    tr {
                    td {
                        	+"First Name :"
                    }
                    td {
                    input { 
						id="txtFirstName" 
						type=InputType.text 
						this.attributes.put("class", "inputRequired")
                    }
                    }
                    }
                    tr {
                    td {
                        	+"Last Name :"
                    }
                    td {
                    input { 
						id="txtLastName" 
						type=InputType.text 
						this.attributes.put("class", "inputRequired")
                    }
                    }
                    }
                    tr {
                    td {
                        	+"City :"
                    }
                    td {
                    select { 
						id="addCity"  
						this.attributes.put("class", "inputRequired")
                    option { 
						value="Select"
                    	+"Select"
                    }
                    option { 
						value="New York"
                    	+"New York"
                    }
                    option { 
						value="New Delhi"
                    	+"New Delhi"
                    }
                    option { 
						value="London"
                    	+"London"
                    }
                    }
                    }
                    }
                    tr {
                    td {
                        	+"Favourite Color"
                    }
                    td {
                    input { 
						id="radioRed" 
						type=InputType.radio 
						name="color" 
						value="Red" 
						this.attributes.put("class", "inputRequired")
                    }
                    	+"Red"
                    input { 
						id="radioGreen" 
						type=InputType.radio 
						name="color" 
						value="Green" 
						this.attributes.put("class", "inputRequired")
                    }
                    	+"Green"
                    input { 
						id="radioBlue" 
						type=InputType.radio 
						name="color" 
						value="Blue" 
						this.attributes.put("class", "inputRequired")
                    }
                    	+"Blue"
                    }
                    }
                    tr {
                    td {
                        	+"Contact Method"
                    }
                    td {
                    input { 
						type=InputType.checkBox 
						id="chkEmail" 
						name="skills" 
						value="Email" 
						this.attributes.put("class", "inputRequired")
                    }
                    	+"Email"
                    input { 
						type=InputType.checkBox 
						id="chkPhone" 
						name="skills" 
						value="Phone" 
						this.attributes.put("class", "inputRequired")
                    }
                    	+"Phone"
                    input { 
						type=InputType.checkBox 
						id="chkSocial" 
						name="skills" 
						value="Social Media" 
						this.attributes.put("class", "inputRequired")
                    }
                    	+"Social Media"
                    }
                    }
                    tr {
                    td {
                        	+"Comments"
                    }
                    td {
                    textArea {
                    }
                    }
                    }
                    tr {
                    td {
                    input { 
						type=InputType.submit 
						value="submit"
                    }
                    }
                    td {
                    div { 
						id="cityResult"
                    }
                    }
                    }
                    }
                    br{ }
					br{ }
                    div { 
						id="divResult"
                    }
                    div { 
						id="resultDiv"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./026_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    style {
                        +".textBoxStyle {"
                        +"background-color: green;"
                        +"color: white;"
                    +"}"
                    }
                    input { 
						id="btnClickMe" 
						type=InputType.button 
						value="Click Me"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./027_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    style {
                        +".textBoxStyle {"
                        +"background-color: green;"
                        +"color: white;"
                    +"}"
                    }
                    input {
						id="btnAdd1"
						type=InputType.button
						value="Add a new List Item"
                    }
                    ul {
						id="ul1"
                    li {
                        +"List Item"
                    }
                    li {
                        +"List Item"
                    }
                    }
                    br{ }
					br{ }
                    input {
						id="btnAdd2"
						type=InputType.button
						value="Add a new List Item"
                    }
                    ul {
						id="ul2"
                    li {
                       +"List Item"
                    }
                    li {
                        +"List Item"
                    }
                    }
                    br{ }
					br{ }
                    input {
						id="btnAdd3"
						type=InputType.button
						value="Add a new List Item"
                    }
                    input {
						id="btnUndelgate"
						type=InputType.button
						value="Undelegate"
                    }
                    ul {
						id="ul3"
                    li {
                        +"List Item"
                    }
                    li {
                        +"List Item"
                    }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./028_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"
                    style {
                        +".textBoxStyle {"
                        +"background-color: green;"
                        +"color: white;"
                    +"}"
                    }
                    table {
                        tr {
                            td {
                                    +"First Name :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                        tr {
                            td {
                                +"Last Name :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                        tr {
                            td {
                                +"Gender :"
                            }
                            td {
                                select {
                                    option {
                                        value="male"
                                        +"Male"
                                    }
                                    option {
                                        value="female"
                                        +"Female"
                                    }
                                }
                            }
                        }
                        tr {
                            td {
                                +"Email :"
                            }
                            td {
                                input {
                                    type=InputType.text
                                }
                            }
                        }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./029_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body { 
						style="font-family:Arial"
                    style {
                        +".textBoxStyle {"
                        +"background-color: green;"
                        +"color: white;"
                        +"}"
                    }
                    a { 
						id="myHyperLink" 
						href="http://pragimtech.com"
                    	+"Clicking here does not take you to PragimTech.com"
                   }
                    h4 {
                            	+"Right click disabled on this page. Try to right click and see what happens."
                   }
                    div { 
						id="divResult"
                   }
                    br {
					}
					br{ }
                    div { 
						style="width:600px; height:200px; border:1px solid black; overflow:scroll"
                    	+"She thrust both hands forward, one placed atop the other. Then drawing"
                    	+"them apart, span with such a rapid movement, it was impossible to tell where"
                    	+"the girl began and the plume of dust that rose in her wake ended. Stopping all at once, she stepped free of the settling dust with slow,"
                    	+"languorous steps, exposing the bronze shapely dancer’s leg lying beneath the"
                    	+"hem of her skirt. Her hair moved slightly, revealing snapshots of her eyes and"
                    	+"her mysterious smile. The teen placed slender arms together again, creating small wave-like"
                    	+"movements starting from her hands folded atop each other - she progressed"
                            	+"the waveforms to her entwined arms, then to her supple torso."

                    	+"Tanned arms, still entwined together, followed the fluttering movement of"
                    	+"her hands as they moved like a bird’s delicate wings. Drawing them upwards"
                            	+"until her hands were vertical, she cut sensual shapes in the air, parting the"
                    	+"veil which lay over her face. They revealed hazel eyes which shone with religious peace, mysteriously"
                    	+"blissful. Her arms began to caress her skin as her long straight legs drew arc- circles in the dust. Twirling once more, arms curled around her midriff, she"
                    	+"paused to scoop more handfuls of sand before drawing herself up again."

                    	+"She began to effortlessly gyrate with the skillful ease of a belly-dancer, snaking her hips around the strings of the melody. Stretching her arms out"
                    	+"towards her sides, watchers lost themselves in her motion. Then bursting into frenzy, sand erupted from her outstretched arms, leaving"
                    	+"trails in air as she spun with ecstatic speed, a whirling dervish - drums rose to"
                    	+"fever pitch, tapping the energy of invigorated limbs."
                   }
                    br {
					}
                    h3 { 
						style="display:none; color:red"
                    	+"Scroll event handled "
                    span {
                            	+"0"
                   }
                    	+" time(s)"
                   }
                    h4 {
                            	+"Current scroll position:"
                    div { 
						id="last"
                   }
                   }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./030_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                    script(src="")
                }
                body { 
						style="font-family:Arial"
                    style {
                            +".imgStyle"
                    +"{"
                        +"height:102px;"
                        +"width:280px;"
                        +"border:3px solid white;"
                    +"}"
                   }
                    select { 
						id="selectImgEffect"
                    option { 
						value="Fade"
                    	+"Fade"
                   }
                    option { 
						value="Slide"
                    	+"Slide"
                   }
                   }
                    	+" Time in seconds : "
                    select { 
						id="selectImgDuration"
                        option {
                            value="2"
                            +"2"
                       }
                        option {
                            value="3"
                            +"3"
                       }
                        option {
                            value="4"
                            +"4"
                       }
                        option {
                            value="5"
                            +"5"
                       }
                        option {
                            value="6"
                            +"6"
                        }
                        option {
                            value="7"
                            +"7"
                        }
                        option {
                            value="8"
                            +"8"
                        }
                        option {
                            value="9"
                            +"9"
                        }
                        option {
                            value="10"
                            +"10"
                        }
                   }
                    input { 
						type=InputType.button 
						id="btnEnlarge" 
						value="Enlarge"
                   }
                    input { 
						type=InputType.button 
						id="btnShrink" 
						value="Shrink"
                   }
                    input {
                        type=InputType.button
                        id="btnStartSlideShow"
                        value="Start Slideshow"
                    }
                    input {
                        type=InputType.button
                        id="btnStopSlideShow"
                        value="Stop Slideshow"
                    }
                    br {
					}
					br{ }
                    img { 
						id="mainImage" 
						height="307"
						width="844" 
						style="border:21px solid white" 
						src="Africa002.jpg"
                   }
                    div { 
						id="divContainer"
                    br {
					}
                    img { 
						src="Africa003.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa004.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa005.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa006.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa007.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa008.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa009.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa010.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa011.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa012.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa013.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa014.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa015.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa016.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa017.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa018.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa019.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa020.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa021.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa022.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa023.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa024.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa025.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa026.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa027.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa028.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa029.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                    img { 
						src="Africa030.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa031.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    img { 
						src="Africa032.jpg" 
						this.attributes.put("class", "imgStyle")
                   }
                    br {
					}
					br{ }
                   }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./031_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body { style="font-family:Arial"

                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./032_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body { 
						style="font-family:Arial"
                    	+"Select Percentage :"
                    select { 
						id="addPercentage"
                    option { 
						value="10"
                    	+"10"
                   }
                    option { 
						value="20"
                    	+"20"
                   }
                    option { 
						value="30"
                    	+"30"
                   }
                    option { 
						value="40"
                    	+"40"
                   }
                    option { 
						value="50"
                    	+"50"
                   }
                    option { 
						value="60"
                    	+"60"
                   }
                    option { 
						value="70"
                    	+"70"
                   }
                    option { 
						value="80"
                    	+"80"
                   }
                    option { 
						value="90"
                    	+"90"
                   }
                    option { 
						value="100"
                    	+"100"
                   }
                   }
                    input { 
						type=InputType.button 
						id="myButton" 
						value="Start Animation"
                   }
                    br {
					}
					br{ }
                    div { 
						id="outerDiv" 
						style="background-color:#EEEEEE; height:20px; width:500px; padding:5px"
                    div { 
						id="innerDiv" 
						style="background-color:red; height:19px; width:0px; color:white; text-align:center"
                   }
                   }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./033_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                    style {
                        +".divClass"
                        +"{"
                            +"font-size: 16px;"
                            +"background-color: #E3E3E3;"
                            +"width: 500px;"
                            +"padding: 5px;"
                        +"}"
                    }
                }
                body {
						style="font-family:Arial"
                    	+"Password :"
                    input { 
						type=InputType.password 
						id="txtPassword"
                   }
                    input { 
						type=InputType.checkBox 
						id="cbShowPassword"
                   }
                    	+"Show password"
                    br {
					}
					br{ }
                    	+"Font-Size :"
                    a { 
						id="linkIncrease" 
						href="#"
                    	+"Increase"
                   }
                    a { 
						id="linkDecrease" 
						href="#"
                    	+"Decrease"
                   }
                    a { 
						id="linkReset" 
						href="#"
                    	+"Reset"
                   }
                    br {
					}
					br{ }
                    div { 
						id="divContent" 
						this.attributes.put("class", "divClass")
                    b {
                            	+"jQuery Tutorial"
                   }
                    ul {
                    li {
                            	+"What is jQuery"
                           }
                    li {
                            +"What is $(document).ready(function() in jquery"
                   }
                    li {
                            	+"Benefits of using CDN"
                   }
                    li {
                                +"#id selector"
                   }
                    li {
                            	+"Element Selector"
                   }
                    li {
                    	+"class Selector"
                   }
                    li {
                            	+"attribute Selector"
                   }
                    li {
                            	+"attribute value Selector"
                   }
                    li {
                            	+"case insensitive attribute Selector"
                   }
                    li {
                            	+"jQuery input vs :input"
                   }
                   }
                   }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./034_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
					style="font-family:Arial"
					style {
						+"#popup-container {"
						+"position: absolute;"
						+"left: 25%;"
						+"top: 10%"
						+"z-index: 11111;"
						+"width: 340px;"
						+"padding: 20px;"
						+"border: 1px solid #ccc;"
						+"box-shadow: 0px 0px 10px #ccc;"
						+"display: none;"
						+"background-color: white;"
						+"}"
						+"#close-btn {"
						+"float: right;"
						+"cursor: pointer;"
						+"}"
					}
                    table { 
						this.attributes.put("align", "center")
                    tr {
                    td { 
						style="width:500px"
                    h4 {
                        +"34-27 Medusa’s Path"
					}
                    h5 {
                        +"Running time: 6:14, Reading speed: ~250 wpm"
					}
                    	+"Characters: Imur, Ehud"
                   +"(0:00)"
                    p {
                        +"A tall, gracile, brown-eyed girl entered the circle, raven hair shading her face,"
                    	+"revealing a straight aquiline nose. A wide, tan coloured skirt stretched down"
                    	+"past her knees, but her feet were bare."
                    	+"She dropped to the ground suddenly, beginning to gyrate her bare midriff,"
                    	+"revealing for a moment a glimpse of her eyes. Leaning forward, she scooped"
                    	+"2"
                    	+"large handfuls of loose dry soil, leaking from her fingers as her arms began to"
                    	+"rise."
                    	+"Spirals of dust were left twirling in the midday sun, before an unseen"
                    	+"movement made both handfuls explode in a greyish-brown cloud, obscuring"
                    	+"her from view - plumes erupted, girl invisible behind spraying fountains."
                    	+"More spirals appeared amidst the smoke as the girl rose to her feet, twisting"
                    	+"her body with one skillful movement. Her hands moved independently,"
                    	+"creating shapes in the falling sand as she turned in a graceful arc."
                   +"(0:34)"
                    	+"She thrust both hands forward, one placed atop the other. Then drawing"
                    	+"them apart, span with such a rapid movement, it was impossible to tell where"
                    	+"the girl began and the plume of dust that rose in her wake ended."
                    	+"Stopping all at once, she stepped free of the settling dust with slow,"
                    	+"languorous steps, exposing the bronze shapely dancer’s leg lying beneath the"
                    	+"hem of her skirt. Her hair moved slightly, revealing snapshots of her eyes and"
                    	+"her mysterious smile."
                    	+"The teen placed slender arms together again, creating small wave-like"
                    	+"movements starting from her hands folded atop each other - she progressed"
                            	+"the waveforms to her entwined arms, then to her supple torso."
                   +"(1:01)"
                    	+"Tanned arms, still entwined together, followed the fluttering movement of"
                    	+"her hands as they moved like a bird’s delicate wings. Drawing them upwards"
                            	+"until her hands were vertical, she cut sensual shapes in the air, parting the"
                    	+"veil which lay over her face."
                    	+"They revealed hazel eyes which shone with religious peace, mysteriously"
                    	+"blissful. Her arms began to caress her skin as her long straight legs drew arccircles"
                    	+"in the dust. Twirling once more, arms curled around her midriff, she"
                    	+"paused to scoop more handfuls of sand before drawing herself up again."
                    	+"3"
                    	+"She began to effortlessly gyrate with the skillful ease of a belly-dancer,"
                    	+"snaking her hips around the strings of the melody. Stretching her arms out"
                            	+"towards her sides, watchers lost themselves in her motion."
                    	+"Then bursting into frenzy, sand erupted from her outstretched arms, leaving"
                    	+"trails in air as she spun with ecstatic speed, a whirling dervish - drums rose to"
                    	+"fever pitch, tapping the energy of invigorated limbs."
                   +"(1:45)"
                    	+"Dust clouded the area enclosed by the circle, sunlight glinting off the bangles"
                    	+"at her wrists and ankles. Strings’ echoes became harsher, assonant, more"
                    	+"frequent in her frenzy - watchers couldn’t help being swept away by her"
                            	+"performance, body flipping with an acrobat’s ease."
                   +"(1:54)"
                    	+"side."
                    	+"with the breeze generated by her movements."
                    	+"One of her long lean legs snapped up from under her dress, stretching to the"
                    	+"sky as she pirouetted on her toes. The next moment she was springing"
                            	+"forwards, airborne before rolling through to her feet."
                   +"(2:11)"
                    	+"The man he spoke to nodded. Possessing a swarthy black beard with a scar"
                    	+"crossing the eyebrow above his right eye, he tracked the dancing girl’s"
                    	+"movements."
                    	+"4"
                   +"(2:19)"
                    	+"with a smile."
                   +"(2:24)"
                    	+"He had a head full of thick silver hair and a short, full beard. Skin darkened by"
                    	+"the sun, his face was wrinkled with such jovial-cut lines one couldn’t help but"
                    	+"like him."
                    	+"The travelers’ leader bowed his head. Tall, clean-shaven - the lieutenant at his"
                    	+"side’s barrel chest and piercing eyes said he was not one to mess with."
                    	+"share. You see we are on a very special mission at the moment.”"
                    	+"The Baul leader smiled graciously."
                   +"(2:47)"
                    	+"grateful for the repast.”"
                    	+"He bowed his head in imitation of the traveler. The young man gave a"
                    	+"charming smile and spoke."
                        	+"age. She’s not a Templar is she?”"
                    	+"Lalon raised his head."
                    	+"The young man showed his palms."
                    	+"wariness. “We work in the employ of a very wealthy king - his court has need"
                            	+"5"
                    	+"of dancers, not harem dwellers. I swear to you, no disgrace will come to your"
                    	+"daughter.”"
                    	+"He opened a pouch at his side, a small bag full of gold coins."
                    	+"one with talent.”"
                   +"(3:21)"
                    	+"Lalon looked distrustful at the sight of the offering."
                    	+"A single red dot was painted in the centre of his forehead, his eyebrows"
                    	+"raised in an unaccustomed frown. The young man saw the older one’s"
                    	+"expression, and put his money away."
                    	+"is not for sale.”"
                   +"(3:38)"
                    	+"He motioned to another man, a quick devious looking fellow with a hooked"
                    	+"nose."
                    	+"a good drink.”"
                    	+"She lay hidden under piles of food and water containers thinking about her"
                    	+"father when she heard the first noises of the commotion. Steel clashed with"
                    	+"steel amidst the sound of screams."
                    	+"6"
                    	+"Animal noises began to intermingle with the chaos of the disturbance. In an"
                            	+"effort to escape the mayhem, donkeys rushed past the tents, knocking over"
                    	+"support poles. Scared by the noises, she pulled the sheets overhead."
                   +"(4:10)"
                    	+"She could hear men barking, shouting orders, bellowing at the frightened"
                    	+"travellers."
                    	+"Steel still rang against steel. Somewhere she could hear a horse’s whinny and"
                            	+"the beginning of galloping hooves throughout the camp. They passed"
                    	+"worryingly close to the equipment cart she was in."
                            	+"Flames had broken out. Her first indication that they had started was the"
                            	+"smell of burning fabric leaking through the air. She fought against an urge to"
                    	+"poke her head out from her hiding spot."
                   +"(4:30)"
                    	+"Was that another scream? What was happening? Was the burning smell"
                    	+"getting stronger?"
                   +"(4:34)"
                    	+"She reluctantly unearthed her head and caught glimpse of a dull red glow"
                    	+"beyond the entrance of the supply tent."
                   +"(4:39)"
                    	+"A sudden explosion rocked the entire camp, sending bright light and heat"
                    	+"straight through the fabric of the tent. The girl ducked under the covering and"
                    	+"began cowering. Tears streaked down her face as she shivered."
                   +"(4:47)"
                    	+"She’d seemed so possessed and self-confident during the dance routine, but"
                    	+"in reality she was just a 17-year old."
                    	+"7"
                   +"(4:52)"
                    	+"The sound of clashing arms continued for a few more moments, and all of a"
                    	+"sudden ended with an agonizing yell."
                   +"(4:56)"
                    	+"Then just as soon as it had started, everything was quiet, she could hear"
                    	+"nothing but the crackle of flames."
                   +"(5:01)"
                    	+"She slowly raised the covering blanket again, listening for conversation amidst"
                    	+"the heat of the smouldering fires."
                   +"(5:05)"
                    	+"impatience."
                   +"(5:09)"
                    	+"His features betrayed his bare fury."
                   +"(5:14)"
                    	+"One of the other attackers returned. He eyed the tall man with a degree of"
                            	+"hesitation."
                           +"(5:18)"
                    	+"as a means of appeasing the young man."
               +"(5:21)"
                    	+"Ehud turned his eyes upon the newcomer. The charm in his expression had"
                            	+"entirely disappeared, his eyes now dark black coals."
                    	+"8"
                    	+"The man fidgeted nervously with his sword belt."
                    	+"Ehud didn’t reply straight away, taking his time formulating the next sentence."
                    	+"missing, not even a donkey. Her clothes are still in her tent. You’re telling me"
                    	+"they have sent a teenage girl alone into the wilderness, with no pack animal,"
                    	+"no clothes?!”"
                    	+"He motioned to the group of people corralled on the floor."
                    	+"For a moment there was silence, then shuffling."
                    	+"The girl soon appeared, escorted by Captain Ehud’s men."
                    	+"Lalon’s eyes filled with tears."
                    	+"He started up, as soldiers aimed the points of their blades at his chest."
                    	+"Ehud spoke as the girl approached."
                    	+"to your daughter.”"
                    	+"follow.”"
                    	+"9"
                    	+"34-28 Donyaye in Roozaye Man"
                    	+"Running time 4:53 minutes, Reading speed ~237 wpm"
                    	+"Characters: Imur, Ehud"
                   +"(0:05)"
                    	+"She laid the flowers the same way every night, gathered from fields she"
                    	+"passed as they journeyed through. She had done this every day since she was"
                        	+"a child, the smell of petals on her folded cloth pillow reminding her of the"
                    	+"fragrance of her homeland."
                    	+"The men kept their distance, never talked and barely looked, checking only"
                    	+"that she was present. Escape attempts had ended in misery, so she tried to"
                    	+"forget; wandering between horses, lost in her thoughts, she picked flowers"
                    	+"when she could."
                    	+"Yeras, a black bearded man, eyed her warily when she came near - like others"
                    	+"he didn’t say a word."
                    	+"Her days were occupied by thoughts of her family, the Bauls, and poor"
                    	+"Rashmith who she’d last seen lying there, unmoving."
                   +"(0:36)"
                    	+"Rashmith…"
                    	+"She made sure to scowl at their leader, Ehud or whatever his name was,"
                    	+"whenever he walked along the line, checking animals, men and equipment."
                    	+"Out of all the soldiers, he was the only one who tried to make conversation"
                    	+"with her."
                    	+"Responding the same way Yeras did when expressing his displeasure, she"
                    	+"turned her head to spit upon the ground. Men stared in shock, unused to"
                    	+"seeing Ehud disobeyed or challenged."
                    	+"10"
                   +"(0:56)"
                    	+"She’d seen firsthand how cruel their leader could be. On their first night,"
                    	+"Yeras gave one of his soldiers a choice, either fall on his sword, or be left in"
                    	+"the wilderness. From what she gathered, the second option involved breaking"
                    	+"his legs - he chose to fall on his sword."
                    	+"As he was the only one who would actually look at her, Imur asked Yeras"
                    	+"what the soldier’s crime had been. He’d replied to her in his gruff voice."
                   +"(1:15)"
                    	+"By the time night fell on the 9th day, Imur was so far from her homeland she"
                    	+"was sure she’d never refind the campsite of the travelling Bauls. She held a"
                    	+"faint hope they’d followed her trail, finding freshly picked petals she scattered"
                    	+"every night."
                    	+"It was only a faint hope. Her people were musicians, singers, entertainers."
                    	+"Few amongst them could wield a sword, let alone stand against these soldiers."
                   +"(1:33)"
                    	+"It had become clear that this was what they were."
                	+"Ehud was their leader, and a discernible military structure flowed down from"
                    	+"his command through the second in the chain, Yeras."
                   +"(1:42)"
                    	+"The night was a dark and starless one, sleep not yet approaching when she"
                    	+"felt the hand snake over her mouth. She let out a shriek, tried to kick against"
                    	+"her attacker, but he placed his hand around her neck blocking her airways."
                   +"(1:52)"
                	+"11"
                    	+"His grip loosened as he emitted a strange gurgling noise. With a final buck of"
                            	+"her hips, Imur threw her assailant aside."
                    	+"Struggling for purchase on the dry dirt, he tried in vain to raise himself as a"
                    	+"dark liquid leaked from his open mouth. He collapsed in a heap, pressed"
                    	+"down by a heavy boot."
                        	+"can?”"
                    	+"Imur recognized the growl, the silhouetted form of the beard on the cloudless"
                    	+"night."
                   +"(2:12)"
                    	+"The figure on the floor attempted to make a response, but the bearded form"
                    	+"knelt over him to twist the knife in deeper. The grounded man let out a yell."
                    	+"man up with bristling forearms."
                   +"(2:21)"
                    	+"They disappeared into the night."
                    	+"he marched her assailant away."
                   +"(2:27)"
                    	+"In the morning Imur did not have to count to know there was a soldier"
                    	+"missing. She thought she could remember his face in the darkness. Short,"
                    	+"wide-eyed and square."
                   +"(2:35)"
                    	+"Ehud made no mention of the incident. Not to the men, and certainly not to"
                    	+"12"
                    	+"her. They simply got on with travelling as if nothing had happened. Death, it"
                    	+"seemed, was a very real possibility in Ehud’s travelling company."
                   +"(2:44)"
                    	+"Despite herself, upon noticing this she burst into heavy tears, continuing until"
                    	+"she felt herself lifted bodily off the ground - before she knew what had"
                    	+"happened, she’d been placed atop a horse’s saddle. She raised her eyes to"
                    	+"see Ehud walking into the distance. Trying to dismount, Yeras held her steady."
                    	+"disagreement."
                   +"(3:03)"
                    	+"Imur slowly swung her leg back over the saddle, wiping her eyes once more."
                    	+"The tears continued to streak her light tan face as she rode that day. The road"
                    	+"occasionally blurred before her eyes, hands remaining clenched on the hard"
                    	+"leather strap of the horse’s reins. Beyond the cloth saddle and the brown"
                    	+"velvet stallion’s back all else ceased to exist."
                   +"(3:22)"
                    	+"She came down at midday. Nothing had changed, none of the men looked at"
                    	+"her. Yeras sat eating a hunk of dry bread and cheese, heavy scowl on his face."
                    	+"Imur dipped her own generously rationed flatbread in the milk provided, and"
                    	+"tore into it with a lump of cheese. She watched Yeras chew as his piercing"
                            	+"eyes swivelled towards her."
                    	+"She took her opportunity,"
                    	+"handing it to him."
                    	+"He accepted her offer with a grunt. Chewing silently for a couple of minutes,"
                    	+"he finished his meal before returning an answer."
                    	+"13"
                    	+"She scrambled up following him."
                    	+"stride."
                    	+"He cursed, still walking. Finally after a few seconds he turned to face her."
                    	+"his answer."
                   +"(4:00)"
                    	+"The wind was bitterly cold the next morning as they sheltered at the side of a"
                            	+"mountain pass."
                    	+"Blanket wrapped around her shoulders, she shivered relentlessly in the"
                    	+"freezing air. One of the men, a slim cut man with curly hair and a stern face"
                    	+"that implied he was in his late 40s brought her a cup of steaming broth from"
                    	+"the fireside. Shivering, she nodded her thanks as she briefly unwrapped her"
                    	+"blanket to receive the gift."
                   +"(4:19)"
                    	+"Her limbs ached with the effort of yesterday’s chase; borrowed horse"
                        	+"galloping full speed for the mountains of the east, for her family and home."
                    	+"She’d looked behind her breathlessly. Only one pursuer, one rider – Ehud."
                    	+"Letting the heat from the wooden bowl seep into her hands, she blew on the"
                    	+"steamed contents; feeling the gift of warm air hitting her cold nose, she"
                    	+"tentatively took a sip."
                    	+"Imur remembered rushing into the water, throwing her head underneath,"
                    	+"and diving for the bottom."
                    	+"14"
                    	+"The next waking up coughing and spluttering warm water in the bright"
                            	+"sunlight."
                    	+"By the time they reached a tall, grey fort on a tabletop mountain, her heart"
                    	+"was so heavy the sight barely registered."
                    	+"Yeras rode out before the front gates, saluting his captain as he approached."
					}
                   }
                    td { 
						style="width:150px"
                    div { 
						id="sidePanel"
                    	+"Side Panel"
                    br {
					}
					br{ }
                    button { 
						id="show-popup-btn"
                    	+"Show Popup"
                   }
                   }
                    div { 
						id="popup-container"
                    div { 
						id="close-btn-container"
                    button { 
						id="close-btn"
                    	+"Close"
                   }
                   }
                    h5 {
                        	+"Some content"
                   }
                   }
                   }
                   }
                   }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./035_jquery/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/html-dsl") {
            call.respondHtml {
                head{
                    link(href="/static/dynamic_styles.css", type="text/css", rel="stylesheet")
                }
                body {
                    h1 { +"CSS-DSL Example with advanced CSS" }
                    div("colorchange") {
                        +"Hi this ia a color changing box"
                    }
                    div("divblue") {
                        +"Hi this ia a blue box"
                    }
                    div("divgreen") {
                        +"Hi this ia a green box"
                    }
                    div("divbrown") {
                        +"Hi this ia a brown box. The color is made from a hex value"
                    }
                    img(src="/static/ktor_logo.svg")
                    script(type="application/javascript", src="/static/myjavascript.js"){}
                }
            }
        }

        get("/help") {
            call.respondHtml {
                head { }
                body {
                    div {
                        id = "firstNameHelpDiv"
                        +"Your first name as it appears in passport"
                    }

                    div {
                        id = "lastNameHelpDiv"
                        +"Your last name as it appears in passport"
                    }

                    div {
                        id = "emailHelpDiv"
                        +"Your email address for communication"
                    }

                    div {
                        id = "incomeHelpDiv"
                        +"Your annual income"
                    }
                }
            }
        }

        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    style="font-family:Arial"

                    table {
                        tr {
                            td {
                                +"First Name"
                            }
                            td {
                                input {
                                    type=InputType.text
                                    id="firstName"
                                }
                            }
                            td {
                                div {
                                    id="firstNameHelpDiv"
                                }
                            }
                        }
                        tr {
                            td {
                                +"Last Name"
                            }
                            td {
                                input {
                                    type=InputType.text
                                    id="lastName"
                                }
                            }
                            td {
                                div {
                                    id="lastNameHelpDiv"
                                }
                            }
                        }
                        tr {
                            td {
                                +"Email"
                            }
                            td {
                                input {
                                    type=InputType.text
                                    id="email"
                                }
                            }


                            td {
                                div {
                                    id="emailHelpDiv"
                                }
                            }
                        }
                        tr {
                            td {
                                +"Income"
                            }
                            td {
                                input {
                                    type=InputType.text
                                    id="income"
                                }
                            }
                            td {
                                div {
                                    id="incomeHelpDiv"
                                }
                            }
                        }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./ajax001/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/html-dsl") {
            call.respondHtml {
                head{
                    link(href="/static/dynamic_styles.css", type="text/css", rel="stylesheet")
                }
                body {
                    h1 { +"CSS-DSL Example with advanced CSS" }
                    div("colorchange") {
                        +"Hi this ia a color changing box"
                    }
                    div("divblue") {
                        +"Hi this ia a blue box"
                    }
                    div("divgreen") {
                        +"Hi this ia a green box"
                    }
                    div("divbrown") {
                        +"Hi this ia a brown box. The color is made from a hex value"
                    }
                    img(src="/static/ktor_logo.svg")
                    script(type="application/javascript", src="/static/myjavascript.js"){}
                }
            }
        }

        get("/help") {
            call.respondHtml {
                head { }
                body {
                    div {
                        id = "firstNameHelpDiv"
                        +"Your first name as it appears in passport"
                    }

                    div {
                        id = "lastNameHelpDiv"
                        +"Your last name as it appears in passport"
                    }

                    div {
                        id = "emailHelpDiv"
                        +"Your email address for communication"
                    }

                    div {
                        id = "incomeHelpDiv"
                        +"Your annual income"
                    }
                }
            }
        }

        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    button {
                        id = "myButton"
                        +"Get Text File"
                    }
                    br {}
                    br {}
                    div {
                        id = "text"
                    }

                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./ajax002/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/html-dsl") {
            call.respondHtml {
                head{
                    link(href="/static/dynamic_styles.css", type="text/css", rel="stylesheet")
                }
                body {
                    h1 { +"CSS-DSL Example with advanced CSS" }
                    div("colorchange") {
                        +"Hi this ia a color changing box"
                    }
                    div("divblue") {
                        +"Hi this ia a blue box"
                    }
                    div("divgreen") {
                        +"Hi this is a green box"
                    }
                    div("divbrown") {
                        +"Hi this ia a brown box. The color is made from a hex value"
                    }
                    img(src="/static/ktor_logo.svg")
                    script(type="application/javascript", src="/static/myjavascript.js"){}
                }
            }
        }

        get("/help") {
            call.respondHtml {
                head { }
                body {
                    div {
                        id = "firstNameHelpDiv"
                        +"Your first name as it appears in passport"
                    }

                    div {
                        id = "lastNameHelpDiv"
                        +"Your last name as it appears in passport"
                    }

                    div {
                        id = "emailHelpDiv"
                        +"Your email address for communication"
                    }

                    div {
                        id = "incomeHelpDiv"
                        +"Your annual income"
                    }
                }
            }
        }

        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    button {
                        id = "button1"
                        +"Get User"
                    }
                    button {
                        id = "button2"
                        +"Get Users"
                    }
                    br { }
                    br { }
                    h1{
                        +"User"
                    }
                    div {
                        id= "user"
                    }
                    h1{
                        +"Users"
                    }
                    div {
                        id= "users"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./ajax003/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/html-dsl") {
            call.respondHtml {
                head{
                    link(href="/static/dynamic_styles.css", type="text/css", rel="stylesheet")
                }
                body {
                    h1 { +"CSS-DSL Example with advanced CSS" }
                    div("colorchange") {
                        +"Hi this ia a color changing box"
                    }
                    div("divblue") {
                        +"Hi this ia a blue box"
                    }
                    div("divgreen") {
                        +"Hi this ia a green box"
                    }
                    div("divbrown") {
                        +"Hi this ia a brown box. The color is made from a hex value"
                    }
                    img(src="/static/ktor_logo.svg")
                    script(type="application/javascript", src="/static/myjavascript.js"){}
                }
            }
        }

        get("/help") {
            call.respondHtml {
                head { }
                body {
                    div {
                        id = "firstNameHelpDiv"
                        +"Your first name as it appears in passport"
                    }

                    div {
                        id = "lastNameHelpDiv"
                        +"Your last name as it appears in passport"
                    }

                    div {
                        id = "emailHelpDiv"
                        +"Your email address for communication"
                    }

                    div {
                        id = "incomeHelpDiv"
                        +"Your annual income"
                    }
                }
            }
        }

        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                    style{
                        +".user{"
                        +"display: flex;"
                        +"background-color: #f4f4f4;"
                        +"padding: 10px;"
                        +"margin-bottom: 10px;"
                        +"}"
                        +".user ul{"
                        +"list-style: none;"
                        +"}"
                    }
                }
                body {
                    button {
                        id = "button"
                        +"Load Github Users"
                    }
                    br { }
                    br { }
                    h1 {
                        +"Github Users"
                    }
                    div {
                        id = "users"
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

==> ./ajax004/src/Application.kt <==
package com.example

import io.ktor.locations.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import java.io.File
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    install(Locations) {

    }

    routing {
        get("/html-dsl") {
            call.respondHtml {
                head{
                    link(href="/static/dynamic_styles.css", type="text/css", rel="stylesheet")
                }
                body {
                    h1 { +"CSS-DSL Example with advanced CSS" }
                    div("colorchange") {
                        +"Hi this ia a color changing box"
                    }
                    div("divblue") {
                        +"Hi this ia a blue box"
                    }
                    div("divgreen") {
                        +"Hi this ia a green box"
                    }
                    div("divbrown") {
                        +"Hi this ia a brown box. The color is made from a hex value"
                    }
                    img(src="/static/ktor_logo.svg")
                    script(type="application/javascript", src="/static/myjavascript.js"){}
                }
            }
        }

        get("/process") {
            call.respondHtml {
                head { }
                body {
                    div {
                        id = "firstNameHelpDiv"
                        +"Your first name as it appears in passport"
                    }

                    div {
                        id = "lastNameHelpDiv"
                        +"Your last name as it appears in passport"
                    }

                    div {
                        id = "emailHelpDiv"
                        +"Your email address for communication"
                    }

                    div {
                        id = "incomeHelpDiv"
                        +"Your annual income"
                    }
                }
            }
        }

        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    button {
                        id = "button"
                        +"Click Me"
                    }
                    hr {
                        h1{
                            +"GET FORM"
                        }
                        form(method = FormMethod.get) {
                            input {
                                type = InputType.text
                                name = "name"
                            }
                            input(type = InputType.submit) {
                                formAction = "/process"
                                value = "Submit"
                            }
                        }

                        h1{
                            +"AJAX GET FORM"
                        }
                        form (encType = FormEncType.multipartFormData){
                            id = "getForm"
                            input {
                                id = "name1"
                                type = InputType.text
                                name = "name"
                            }
                            input(type = InputType.submit) {
                                formAction = "/process"
                                value = "Submit"
                            }
                        }
                        h1{
                            +"POST FORM"
                        }
                        form(method = FormMethod.post,
                            encType = FormEncType.multipartFormData) {
                            input(InputType.file, name = "file") {
                                id = "file2"
                            }
                            input(type = InputType.submit) {
                                formAction = "/newprocess"
                                value = "Submit"
                            }
                        }

                        h1{
                            +"AJAX POST FORM"
                        }
                        form(encType = FormEncType.multipartFormData) {
                            id = "postForm"
                            input(InputType.file, name = "file") {
                                id = "file1"
                            }
                            input(type = InputType.submit) {
                                formAction = "/newprocess"
                                value = "Submit"
                            }
                        }
                        h1{
                            +"AJAX NEW NAME POST FORM"
                        }
                        form(encType = FormEncType.multipartFormData) {
                            id = "postNameForm"
                            input {
                                id = "name2"
                                type = InputType.text
                                name = "name"
                            }
                            input(type = InputType.submit) {
                                formAction = "/newprocess"
                                value = "Submit"
                            }
                        }
                        br {}
                        br {}
                        button {
                            id = "userListButton"
                            onClick = "loadUsers()"
                            +"Get User List"
                        }
                        br {}
                        br {}
                        div {
                            id = "resultDiv"
                        }
                        br {}
                        br {}
                        img {
                            id = "img1"
                        }
                    }
                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        post("/process") {
            val parameters = call.receiveParameters()
            parameters.names().forEach {
                val name = parameters.get(it)
                call.respondText { "POST: Your name is $name" }
            }
        }

        post("/newprocess") {
            val multipart = call.receiveMultipart()
            val parameters = processMultiPartData(multipart)
            val file = File(parameters["filename"])

            if (!file.exists()) {
                call.respond(HttpStatusCode.NotFound)
            } else {
                call.respondFile(file)
            }
        }

        get<User> {
            call.respondText { "GET: Your name is ${it.name}" }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}

@Location("/process")
class User(val name: String)

internal suspend fun processMultiPartData(multipart: MultiPartData) : Map<String, String> {
    // retrieve all multipart data (suspending)
    println("Processing Multipart...")
    var parameters = mutableMapOf<String, String>()
    multipart.forEachPart { part ->
        // if part is a file (could be form item)
        when (part) {
            is PartData.FileItem -> {
                println("Processing FILE...")
                // retrieve file name of upload
                val name = part.originalFileName!!
                val ext = name.split('.').last()
                val file = withContext(Dispatchers.IO) {
                    File.createTempFile("temp", ".$ext")
                }
                file.deleteOnExit()
                parameters["filename"] = file.path ?: ""
                // use InputStream from part to save file
                part.streamProvider().use { its ->
                    // copy the stream to the file with buffering
                    file.outputStream().buffered().use {
                        // note that this is blocking
                        its.copyTo(it)
                    }
                }
            }
            is PartData.FormItem -> {
                val name = part.name
                if (name != null) {
                    parameters[name] = part.value
                }
            }
            else -> {
                println(part)
            }
        }
        // make sure to dispose of the part after use to prevent leaks
        part.dispose()
    }

    return parameters
}
==> ./ajax005/src/Application.kt <==
package com.example

import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*
import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.html.*
import kotlinx.html.*
import io.ktor.content.*
import io.ktor.http.content.*
import java.io.FileWriter
import kotlin.math.log

fun main(args: Array<String>): Unit = io.ktor.server.netty.EngineMain.main(args)

@Suppress("unused") // Referenced in application.conf
@kotlin.jvm.JvmOverloads
fun Application.module(testing: Boolean = false) {
    routing {
        get("/html-dsl") {
            call.respondHtml {
                head{
                    link(href="/static/dynamic_styles.css", type="text/css", rel="stylesheet")
                }
                body {
                    h1 { +"CSS-DSL Example with advanced CSS" }
                    div("colorchange") {
                        +"Hi this ia a color changing box"
                    }
                    div("divblue") {
                        +"Hi this ia a blue box"
                    }
                    div("divgreen") {
                        +"Hi this ia a green box"
                    }
                    div("divbrown") {
                        +"Hi this ia a brown box. The color is made from a hex value"
                    }
                    img(src="/static/ktor_logo.svg")
                    script(type="application/javascript", src="/static/myjavascript.js"){}
                }
            }
        }

        get("/help") {
            call.respondHtml {
                head { }
                body {
                    div {
                        id = "firstNameHelpDiv"
                        +"Your first name as it appears in passport"
                    }

                    div {
                        id = "lastNameHelpDiv"
                        +"Your last name as it appears in passport"
                    }

                    div {
                        id = "emailHelpDiv"
                        +"Your email address for communication"
                    }

                    div {
                        id = "incomeHelpDiv"
                        +"Your annual income"
                    }
                }
            }
        }

        get("/") {
            call.respondHtml {
                head{
                    script(src = "jquery-3.6.1.min.js") { }
                }
                body {
                    button {
                        id = "myButton"
                        +"Get Text File"
                    }
                    br {}
                    br {}
                    div {
                        id = "text"
                    }

                    script(type = "text/javascript") {
                        src = "myfile.js"
                    }
                }
            }
        }

        // Static feature. Try to access `/static/ktor_logo.svg
        static("/") {
            resources("")
        }
    }
}
