==> server.js <==
// run using 'node server.js'

const http = require('http');
const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
    res.statusCode = 200;
	res.setHeader('Content-type', 'text/plain');
	res.end('Hello World');
});

server.listen(port, hostname, () => {
    console.log('Server running at http://${hostname}:${port}/');
});

==> ./003_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	alert($('td').length);
	alert($('table').html());
	$('table tr').each(function(){
		alert($(this).html());
	});
	$('div, span, a').css('font-size', '24px');
	$('div a').css('color', 'green');
	$('#table1 tr:even').css('background-color', 'red');
	$('tr:odd').css('background-color', 'yellow');
});
==> ./004_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('.small, .big').css('border', '5px solid red')
	$('.small, span.big').css('font-size', '28px')
	$('#div2 .small, span.big').css('padding-left', '60px')
	$('.small .big').css('color', 'yellow')
});
==> ./005_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('[title="div1Title"]').css('border', '5px solid red')
	$('div[title="div1Title"]').css('color', 'yellow')
	$('p[title][style]').css('border', '5px solid black')
});
==> ./006_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	//$('[title!="div1Title"]').css('border', '5px solid black') //selects all elements title attribute not equal to string
	$('[title*="Title"]').css('border', '5px solid black') //selects all elements that have title attribute containing given substring
	/*$('[title~="myTitle"]').css('border', '5px solid red') //select all elements that contain the current attribute delimited by spaces
	$('[title|="myTitle"]').css('border', '5px solid red') //have title value equal to or starting with myTitle followed by a hyphen
	$('[title^="div"]').css('border', '5px solid red') //selects a title element with an attribute starting with div
	$('[title$="Heading"]').css('border', '5px solid red') //selects a title element with an attribute ending with Heading*/
});
==> ./007_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	/* ('/Div/i' contains a /i flag which says that return attribute is case-insenstive
		return ('/Div/i').test($(this).attr('title'))  //returns the attribute of title
	*/
	/*$('div[title]').filter(function() {
		return ('/Div/i').test($(this).attr('title'));
	}).css('border', '5px solid red');*/ //Syntax not recognized by jquery 3.6.1

	$('div[title]').filter(function() {
		return RegExp('Div', 'i').test($(this).attr('title'));
	}).css('border', '5px solid red');

	$('p[title]').filter(function() {
		return $(this).attr('title').toLowerCase() == "ptitle";
	}).css('border', '5px solid black');
});
==> ./008_jquery/resources/myfile.js <==
/*
	$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
 */
$(document).ready(function(){
	$('input').each(function() {
		alert($(this).val() + " -- input tag");
	});

	$(':input').each(function() {
		alert($(this).val() + " -- form element");
	});
});
==> ./009_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('#btnSubmit').click(function() {
    	var radioresult = $('input[type="radio"]:checked');
    	var resultString = radioresult.length > 0 ? radioresult.val() + " is checked<br/>" :  "No radio buttton checked<br/>";
    	console.log(resultString);

    	var checkresult = $('input[type="checkbox"]:checked');
    	if (checkresult.length > 1) {
    		resultString += checkresult.length + " checkboxes checked<br/>";
    		console.log(resultString);
    		checkresult.each(function() {
    			resultString += $(this).val() + " is checked<br/>";
    			console.log(resultString);
    		})
    	}
    	else if (checkresult.length > 0) {
    		resultString += checkresult.length + " checkbox checked<br/>" + checkresult.val() + " is checked";
    	}
    	else   {
    		resultString += "No checkboxes checked";
    	}
    	$('#divResult').html(resultString);
    });
});
==> ./010_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('#btnGetSelectedSkills').click(function() {
		checkCheckBoxes("skills");
	});

	$('#btnGetSelectedCities').click(function() {
		checkCheckBoxes("cities");
	});

	var checkCheckBoxes = function(name) {
		var checkresult = $('input[name="' + name + '"]:checked');
		var resultString = "";
		if (checkresult.length > 1) {
			resultString = checkresult.length + " checkboxes checked<br/>";
			console.log(resultString);
			checkresult.each(function() {
				resultString += $(this).val() + " is checked<br/>";
				console.log(resultString);
			})
		}
		else if (checkresult.length > 0) {
			resultString = checkresult.length + " checkbox checked<br/>" + checkresult.val() + " is checked";
		}
		else   {
			resultString = "No checkboxes checked";
		}
		$('#divResult').html(resultString);
	};
});
==> ./011_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[name="skills"]').click(function() {
		checkCheckBoxes("skills");
	});

	$('input[name="cities"]').click(function() {
		checkCheckBoxes("cities");
	});

	var checkCheckBoxes = function(name) {
		var checkresult = $('input[name="' + name + '"]:checked');
		var resultString = "";
		if (checkresult.length > 1) {
			resultString = checkresult.length + " checkboxes checked<br/>";
			console.log(resultString);
			checkresult.each(function() {
				resultString += $(this).val() + " is checked<br/>";
				console.log(resultString);
			})
		}
		else if (checkresult.length > 0) {
			resultString = checkresult.length + " checkbox checked<br/>" + checkresult.val() + " is checked";
		}
		else   {
			resultString = "No checkboxes checked";
		}
		$('#div' + name).html(resultString);
	};
});
==> ./012_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[name="skills"]').click(function() {
		checkCheckBoxes("skills");
	});

	$('input[name="cities"]').click(function() {
		checkCheckBoxes("cities");
	});

	var checkCheckBoxes = function(name) {
		var checkresult = $('input[name="' + name + '"]:checked');
		var resultString = "";
		if (checkresult.length > 1) {
			resultString = checkresult.length + " checkboxes checked<br/>";
			console.log(resultString);
			checkresult.each(function() {
				var selectedValue = $(this).val()
				resultString += selectedValue + " - " + $('label[for="cb-' + selectedValue + '"]').text() + "<br/>";
				console.log(resultString);
			})
		}
		else if (checkresult.length > 0) {
			resultString = checkresult.length + " checkbox checked<br/>" + checkresult.val() +  " - " + $('label[for="cb-' + checkresult.val() + '"]').text();
		}
		else {
			resultString = "No checkboxes checked";
		}
		$('#div' + name).html(resultString);
	};
});
==> ./013_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('#selectCountries').change(function() {
		var selected = $('#selectCountries option:selected');
		if (selected.length > 0) {
			var resultString = '';
			selected.each(function() {
				resultString += "Value = " + $(this).val().toUpperCase() + "<br/>Text = " + $(this).text() + "<br/>";
			});
			$('#divResult').html(resultString);
		}
	});
});
==> ./014_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[type="text"]:disabled').css('border', '3px solid red');
});
==> ./015_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	/*$('li').each(function(index, element){
		alert(index + " : " + $(element).text());
	});*/

	/*method chaining will execute each of the following steps in order
	$('li').css('color', 'blue');
	$('li').slideUp(1000);
	$('li').slideDown(1000);
	$('li').attr('title', 'MY TITLE');

	If the previous method does not return an object, i.e. returns a string '.text()', method chaining will not work*/

	$('li').css('color', 'blue').slideUp(1000).slideDown(1000).attr('title', 'MY TITLE');
});
==> ./016_jquery/resources/myfile.js <==
/*
	To select elements by tag name use the jQuery element selector
	$('td') //Select all td elements
	$('div a') //select all anchor elements that are descendants of div elements
	$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	var employeesJSON = [{
		"firstName" : "Todd",
		"lastName" : "Turnip",
		"gender" : "Male",
		"salary" : 50000,
	},
	{
		"firstName" : "Sara",
		"lastName" : "Parsnip",
		"gender" : "Female",
		"salary" : 50000,
	}];

	var result = '';

	$.each(employeesJSON, function (i, item) {
    	result += 'First Name : ' + item.firstName + '<br/>';
    	result += 'Last Name : ' + item.lastName + '<br/>';
    	result += 'Gender : ' + item.gender + '<br/>';
    	result += 'Salary : ' + item.salary + '<br/><br/>';
    });

	$('#divResult').html(result);

	/*employeesJSON.each(function () {
		result += 'First Name : ' + $(this).firstName + '<br/>';
		result += 'Last Name : ' + $(this).lastName + '<br/>';
		result += 'Gender : ' + $(this).gender + '<br/>';
		result += 'Salary : ' + $(this).salary + '<br/>';
	});*/
});
==> ./018_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	/* Retrieves the title attribute of the first matching element
	alert($('div').attr('title'));
	*/

	//$('div').attr('title', 'New DiV Title'); //Would set div title for all elements

	var divs = $('div');

	//Sets a different title attribute for each DIV element
	divs.each(function(i) {
		$(this).attr('title', 'div ' + (i + 1) + ' title');
	});


	//Retrieves the title attribute of every matching element
	$('div').each(function() {
		alert($(this).attr('title'));
	});

	//This creates a Json object which can be passed to the attr method
	var config = {
		'title' : 'New Paragraph Title',
		'style' : 'border:3px solid red',
		'name' : 'My Paragraph'
	};

	//will set these attributes for every paragraph element on the page
	$('p').attr(config);

	var result = '';
	$('p').each(function() {
		result += 'title = ' + $(this).attr('title') + '<br/>';
		result += 'style = ' + $(this).attr('style') + '<br/>';
		result += 'name = ' + $(this).attr('name') + '<br/><br/>';
	});

	$('#resultSpan').html(result);

	//you can remove an attribute using the removeAttr() method, will remove all instances
	$('p[title="New Paragraph Title"]').removeAttr('title');

	$('div[title="div 2 title"]').slideUp(2000).slideDown(2000);

	var divstring = 'Div elements with title attribute = ' + $('div[title]').length + '<br/>';
	divstring += 'Removing title attribute<br/>';
	$('div[title="div 2 title"]').removeAttr('title');
	divstring += 'Div elements with title attribute = ' + $('div[title]').length + '<br/>';

	$('#div2').html(divstring).css('color', 'blue');

	$('div[title]').wrap('<div class="containerDiv"></div>');

	$('<b> Tutorial</b>').appendTo($('div[title]'));
	//also the .append() method

	$('p').prepend('<b>New </b>');
	$('p').append('<br/>');
	$('p').append($('#resultSpan'));
	//also the .prependTo() method

	/*To insert an element before another element there are two methods
		before
		insertBefore
	To insert an element after another element there are also two methods
		after
		insertAfter
	*/
	$('#div1').before('<h3>Easy Programming:</h3>');
	$('<h3>Easy Programming:</h3>').insertBefore('#div3');

	$('#div1').after('<h3>Fun Programming:</h3>');
	$('<h3>Fun Programming:</h3>').insertAfter('#div3');
});
==> ./019_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input').css('width', '250px');

	$('#addColor').click(function() {
		$('p').addClass('colorClass');
	});

	$('#removeColor').click(function() {
		$('p').removeClass('colorClass');
	});

	$('#addItalicsColor').click(function() {
		$('p').addClass('colorClass italicsClass');
	});

	$('#removeItalicsColor').click(function() {
		$('p').removeClass('colorClass italicsClass');
	});

	$('#addAllClasses').click(function() {
		$('p').addClass('colorClass italicsClass boldClass');
	});

	$('#removeAllClasses').click(function() {
		$('p').removeClass('colorClass italicsClass boldClass');
	});
});
==> ./020_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[type="text"]').each(function() {
		$(this).focus(function() {
			console.log("Adding textbox style");
			$(this).addClass('textBoxStyle');
		});

		$(this).blur(function() {
			console.log("Removing textboxStyle");
			$(this).removeClass('textBoxStyle');
		});
	});
});
==> ./021_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	var intArray = [100, 200, 300, 400, 500];

	function functionA(index, element) {
		return element * 5;
	}

	function functionB(element, index) {
		return element * 5;
	}

	/*
		the each method is an immuitable iterator,
		returns the original array,
		The order of callback arguments - index, element
		Return false to terminate the iteration
	*/
	var result1 = $.each(intArray, functionA); //100, 200, 300, 400, 500 (original immutable array)

	/*
		the map method can be used as an iterator
		returns a new array,
		The order of callback arguments - element, index
		Return false to terminate the iteration

	*/
	var result2 = $.map(intArray, functionB); // 500, 1000, 1500, 2000, 2500 (new mutable array)

	//the document.write function provides the entirety of the response, overwriting any HTML elements on the page
	document.write('each = ' + result1);
	document.write('<br/>');
	document.write('map = ' + result2);

	document.write('<br/><br/>');
	$.each(intArray, function (index, element) {
		if (element == 300)
			return false;

		document.write(element + ',');
	});
	//prints 100,200

	document.write('<br/><br/>');
	$.map(intArray, function (element, index) {
		if (element == 300)
			return false;

		document.write(element + ',');
	});
	//prints 100,200,400,500s
});
==> ./022_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[type="text"]').each(function() {
		$(this).focus(function() {
			console.log("Adding textbox style");
			$(this).addClass('textBoxStyle');
		});

		$(this).blur(function() {
			console.log("Removing textboxStyle");
			$(this).removeClass('textBoxStyle');
		});
	});
});
==> ./023_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('#addCity').change(function () {
		var selected = $(this).val();
		if (selected == "Select") {
			selected = "Please select city";
		}

		$('#cityResult').html(selected);
	});

	var result = '';
	$('input').change(function () {
		if (result == '')
		{
			result = $(this).val();
		}
		else
		{
			result += ', ' + $(this).val();
		}
		$('#divResult').html(result);
	});
});
==> ./024_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input').css('width', '250px');
	$('#btn2').mouseup(function(event) {
		var whichButton;
			switch (event.which) {
				case 1: whichButton = "Left Button Clicked"; break;
				case 2: whichButton = "Middle Button Clicked"; break;
				case 3: whichButton = "Right Button Clicked"; break;
				default: whichButton = "Invalid Button Clicked"; break;
			}

		document.getElementById('divResult').innerHTML = whichButton;
	});
});

function whichMouseButtonClicked(event) {
	var whichButton;
	if (event.which) {
		switch (event.which) {
			case 1: whichButton = "Left Button Clicked"; break;
			case 2: whichButton = "Middle Button Clicked"; break;
			case 3: whichButton = "Right Button Clicked"; break;
			default: whichButton = "Invalid Button Clicked"; break;
		}
	}
	else {
		switch (event.button) {
			case 1: whichButton = "Left Button Clicked"; break;
			case 4: whichButton = "Middle Button Clicked"; break;
			case 2: whichButton = "Right Button Clicked"; break;
			default: whichButton = "Invalid Button Clicked"; break;
		}
	}

	document.getElementById('divResult').innerHTML = whichButton;
}
==> ./025_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[type="button"]').css('width', '250px');

	$('#btnClickMe').bind('click mouseover mouseout', function(event) {
		if (event.type == 'click') {
			$('#divResult').html('Button Clicked at X = ' + event.pageX + ' Y = ' + event.pageY);
		}
		else if (event.type == 'mouseover') {
			$(this).addClass('ButtonStyle');
		}
		else {
			$(this).removeClass('ButtonStyle');
		}
	});

	$('#btnEnableMouseOverEffect').click( function() {
		$('#btnClickMe').bind('mouseover', function() {
			$(this).addClass('ButtonStyle');
		});
	});

	$('#btnDisableMouseOverEffect').click( function() {
		$('#btnClickMe').unbind('mouseover');
	});
});
==> ./026_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[type="text"]').each(function() {
		$(this).focus(function() {
			console.log("Adding textbox style");
			$(this).addClass('textBoxStyle');
		});

		$(this).blur(function() {
			console.log("Removing textboxStyle");
			$(this).removeClass('textBoxStyle');
		});
	});
});
==> ./027_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
/*
	$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
 */
$(document).ready(function(){
	$('li').on('click', function() {
		$(this).fadeOut(2000);
	});

	//The following syntax demonstrates how to pass a callback on dynamically created oject
	$('#btnAdd1').on('click', function(){
		var newListItem = $('<li>New List Item</li>').on('click', function() {
			$(this).fadeOut(2000);
		});
		$('#ul1').append(newListItem);
	});

	//The following syntax also demmonstrates how to pass an event handler to a dynamically created object
	//it can even be scoped to specific list items such as li:even
	//When a user inititially clicks on a list item in this example above, the event gets bubbled up to its parent (ul) as the list item
	//li does not have its own event handler. The bubbled event is handled by the parent (#ul2) element as it has a click event handler
	//When a new list item is added dynamically, you don't have to add the click handler explicitly to it. The click event of this new li
	//item is also bubbled up to its parent and handled by it.
	$('#ul2').on('click', 'li', function () {
		$(this).fadeOut(2000);
	});

	$('#btnAdd2').on('click', function(){
		var newListItem = '<li>New List Item</li>';
		$('#ul2').append(newListItem);
	});

	$('#ul3').delegate('click', 'li', function () {
		$(this).fadeOut(2000);
	});

	$('#btnAdd3').on('click', function(){
		var newListItem = '<li>New List Item</li>';
		$('#ul3').append(newListItem);
	});


	$('#btnUndelegate').on('click', function(){
		$('#ul3').off('click', 'li');
	});
});
==> ./028_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[type="text"]').each(function() {
		$(this).focus(function() {
			console.log("Adding textbox style");
			$(this).addClass('textBoxStyle');
		});

		$(this).blur(function() {
			console.log("Removing textboxStyle");
			$(this).removeClass('textBoxStyle');
		});
	});
});
==> ./029_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
/*
	$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
 */
$(document).ready(function(){
	var count = 0;
	//prevents context menu being called (usually with the right-click button)
	$(this).on('contextmenu', function(e){
		e.preventDefault();
		$('#divResult').append('Right Click Disabled<br/>');
	});

	$('#myHyperLink').on('click', function(e){
		e.preventDefault();
		$('#divResult').append('Hyperlink Disabled<br/>');
	});

	$('div').scroll(function() {
		$('h3').css('display', 'inline').fadeOut(1000);
		count = count + 1;
		$('span').text(count);
		var currentScrollPosition = $(this).scrollTop();
		$('#last').text(currentScrollPosition);
	});
});
==> ./030_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
/*
	$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
 */
$(document).ready(function(){
	$('#divContainer img').on({
		mouseover: function () {
			$(this).css({
				'cursor': 'hand',
				'border-color': 'red'
			});
		},
		mouseout: function() {
			$(this).css({
				'cursor': 'default',
				'border-color': 'white'
			}).fade;
		},
		click: function() {
			var imageUrl = $(this).attr('src');
			var effect = $('#selectImgEffect').val();

			if (effect == 'Fade') {
				$('#mainImage').fadeOut(500, function() {
					$(this).attr('src', imageUrl)
				}).fadeIn(500);
			}
			else {
				$('#mainImage').slideUp(500, function() {
					$(this).attr('src', imageUrl)
				}).slideDown(500);
			}
			$('#mainImage').attr('src', imageUrl);
		}
	});

	var height = $('#mainImage').attr('height');
	var width = $('#mainImage').attr('width');

	var tbheight = parseInt($('.imgStyle').css('height'), 10);
	var tbwidth = parseInt($('.imgStyle').css('width'), 10);

	$('#btnEnlarge').click(function() {
		height *= 1.1;
		width *= 1.1;

		$('#mainImage').animate({
			'height' : height,
			'width' : width
		});

		tbheight *= 1.1;
		tbwidth *= 1.1;

		$('.imgStyle').animate({
			'height' : tbheight,
			'width' : tbwidth
		});
	});

	$('#btnShrink').click(function() {
		height /= 1.1;
		width /= 1.1;

		$('#mainImage').animate({
			'height' : height,
			'width' : width
		});

		tbheight /= 1.1;
		tbwidth /= 1.1;

		$('.imgStyle').animate({
			'height' : tbheight,
			'width' : tbwidth
		});
	});

	var imageURLs = new Array();
	var intervalId;
	var btnStart = $('#btnStartSlideShow');
	var btnStop = $('#btnStopSlideShow');

	$('#divContainer img').each(function () {
		imageURLs.push($(this).attr('src'));
	});

	function setImage()
	{
		var mainImageElement = $('#mainImage');
		var currentImageURL = mainImageElement.attr('src');
		var currentImageIndex = $.inArray(currentImageURL, imageURLs);
		if (currentImageIndex == (imageURLs.length - 1))
		{
			currentImageIndex = -1;
		}

		mainImageElement.fadeOut(250).fadeIn(250).attr('src', imageURLs[currentImageIndex +1]);
	}

	btnStart.click(function() {
		var duration = $('#selectImgDuration').val() * 1000;
		intervalId = setInterval(setImage, duration);
		$(this).attr('disabled', 'disabled');
		btnStop.removeAttr('disabled');
	});

	btnStop.click(function() {
		clearInterval(intervalId);
		$(this).attr('disabled', 'disabled');
		btnStart.removeAttr('disabled');
	}).attr('disabled', 'disabled');
});
==> ./031_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
$(document).ready(function(){
	$('input[type="text"]').each(function() {
		$(this).focus(function() {
			console.log("Adding textbox style");
			$(this).addClass('textBoxStyle');
		});

		$(this).blur(function() {
			console.log("Removing textboxStyle");
			$(this).removeClass('textBoxStyle');
		});
	});
});
==> ./032_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
/*
	$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
 */
$(document).ready(function() {
	$('#myButton').click(function() {
		console.log("myButton clicked");
		animateProgressBar($('#addPercentage').val());
	});

	function animateProgressBar(percentageCompleted)
	{
		console.log("animateProgressBar : " + percentageCompleted);
		$('#innerDiv').animate({
			'width':  5 * percentageCompleted
		}, 3000);

		$({counter : 1}).animate({counter: percentageCompleted}, {
			duration: 3000,
			step: function() {
				//.ceil() function rounds up to the nearest integer
				$('#innerDiv').text(Math.ceil(this.counter) + " %");
			}
		});
	};
});
==> ./033_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
/*
$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
*/
$(document).ready(function(){
	$('#linkIncrease').click(function () {
		modifyFontSize('increase');
	});

	$('#linkDecrease').click(function () {
		modifyFontSize('decrease');
	});

	$('#linkReset').click(function () {
		modifyFontSize('reset');
	});

	function modifyFontSize(flag)
	{
		var divElement = $('#divContent');
		var currentFontSize = parseInt(divElement.css('font-size'));

		if(flag == 'increase')
			currentFontSize += 3;
		else if (flag == 'decrease')
			currentFontSize -= 3;
		else
			currentFontSize = 16

		divElement.css('font-size', currentFontSize);
	}

	$('#cbShowPassword').click(function() {
		$('#txtPassword').attr('type', $(this).is(':checked') ? 'text' : 'password')
	});
});
==> ./034_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
/*
	$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
 */
$(document).ready(function() {

	$('#popup-container').hide();

	$('#show-popup-btn').click(function() {
		$('#popup-container').show();
	})

	$('#close-btn').click(function() {
		$('#popup-container').hide();
	});

	var floatingDiv1 = $('#popup-container').position();

	$(window).scroll(function() {
		var scrollBarPosition = $(window).scrollTop();
		$('#popup-container').css({
			'position': 'fixed',
			'top': 250
		});
	});

	var floatingDiv2 = $('#sidePanel').position();

    //A fixed position element is positioned relative to the browser window
	$(window).scroll(function() {
		var scrollBarPosition = $(window).scrollTop();
		$('#sidePanel').css({
			'position': 'fixed',
			'top': 250
		});
	});
});
==> ./035_jquery/resources/myfile.js <==
/*
To select elements by tag name use the jQuery element selector
$('td') //Select all td elements
$('div a') //select all anchor elements that are descendants of div elements
$('div, span, a') // Selects all div, span and anchor elements
*/
/*
$(:input) selects all inputs, textarea, select and button elements where as $(input) just selects elements with an input tag
*/
$(document).ready(function(){
	var textBoxes = $('input[type="text"]');

	textBoxes.focus(function() {
		var helpDiv = $(this).attr('id') + 'HelpDiv';
		$('#' + helpDiv).load('http://localhost:8080/help #' + helpDiv)
		.css({
		    'color' : 'green',
		    'font-style' : 'italic',
		    'font-size' : 12
		})

	});

	textBoxes.blur(function() {
		var helpDiv = $(this).attr('id') + 'HelpDiv';
		$('#' + helpDiv).html('');
	});
});
==> ./ajax001/resources/myfile.js <==
document.getElementById('myButton').addEventListener('click', loadText);

function loadText(){
    //Create XHR object
    var xhr = new XMLHttpRequest();
    // OPEN - type, url/file, async
    console.log(xhr);
    xhr.open('GET', 'words.txt', true);

    console.log('READYSTATE: ', xhr.readyState);
    //onload only operates on readyState = 4
    xhr.onload = function() {
        if(this.status == 200) {
            document.getElementById('text').innerHTML = this.responseText;
        } else if(this.status == 404) {
            document.getElementById('text').innerHTML = "Not found";
        } else {
            document.getElementById('text').innerHTML = "Error";
        }
        console.log(xhr);
    }

    xhr.onerror = function() {
        console.log("Request error");
    }

    // readyState Values
    // 0: request not initialized
    // 1: server connection established
    // 2: request received
    // 3: processing request
    // 4: request finished and response is ready
    xhr.onreadystatechange = function() {
        if(this.readyState != 4) {
            /*do spinny cursor*/
        }
    }

    // Sends request
    xhr.send();
}
==> ./ajax002/resources/myfile.js <==
document.getElementById('button1').addEventListener('click', loadUser);

function loadUser() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'user.json', true);

    xhr.onload = function() {
        if (this.status == 200) {
            //If not wrapped in this JSON.parse() function will not populat eobject
            var user = JSON.parse(this.responseText);
            console.log(user.name);

            var output = '';

            output += '<ul>' +
            '<li>ID: ' + user.id + '</li>' +
            '<li>Name: ' + user.name + '</li>' +
            '<li>Email: ' + user.email + '</li>'
            '</ul>';
            document.getElementById('user').innerHTML = output;
        }
    }

    xhr.send();
}

document.getElementById('button2').addEventListener('click', loadUsers);

function loadUsers() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'users.json', true);

    xhr.onload = function() {
        if (this.status == 200) {
            //If not wrapped in this JSON.parse() function will not populat eobject
            var users = JSON.parse(this.responseText);
            console.log(user.name);

            var output = '';

            for (var i in users) {
                output += '<ul>' +
                '<li>ID: ' + users[i].id + '</li>' +
                '<li>Name: ' + users[i].name + '</li>' +
                '<li>Email: ' + users[i].email + '</li>' +
                '</ul>';
            }
            document.getElementById('users').innerHTML = output;
        }
    }

    xhr.send();
}
==> ./ajax003/resources/myfile.js <==
document.getElementById('button').addEventListener('click', loadUsers);

// Load Github Users
function loadUsers() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://api.github.com/users', true);

    xhr.onload = function(){
        if(this.status == 200){
            var users = JSON.parse(this.responseText);

            console.log(users);

            var output = '';

            for (var i in users) {
                output +=
                    '<div class="user">' +
                    '<img src="' + users[i].avatar_url + '" width="70" height = "70"/>' +
                    '<ul>' +
                    '<li>ID: ' + users[i].id + '</li>' +
                    '<li>ID: ' + users[i].login + '</li>' +
                    '</ul>' +
                    '</div>';
            }

            document.getElementById('users').innerHTML = output;
        }
    }

    xhr.send();
}
==> ./ajax004/resources/myfile.js <==
document.getElementById('button').addEventListener('click', getName);

function getName(){
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'process?name=Les', true);

    xhr.onload = function() {
        console.log(this.responseText)
    }

    xhr.send();
}

document.getElementById('getForm').addEventListener('submit', getName);

function getName(e){
    e.preventDefault();

    var name = document.getElementById('name1').value;

    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'process?name='+name, true);

    xhr.onload = function() {
        console.log(this.responseText)
    }

    xhr.send();
}

document.getElementById('postNameForm').addEventListener('submit', postName);

function postName(e){
    e.preventDefault();
    var file = document.getElementById('file1').files[0];
    var name = document.getElementById('name2').value;
    var parameters = "name="+name;

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'http://localhost:8008/process.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

    xhr.onload = function() {
        console.log(this.responseText)
    }

    xhr.send(parameters);
}

document.getElementById('postForm').addEventListener('submit', postFile);

function postFile(e){
    e.preventDefault();
    var file = document.getElementById('file1').files[0];

    /*var formData = new FormData();
    formData.append('file', file);*/

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'newprocess', true);

    xhr.onload = function() {
        console.log(xhr);
        document.getElementById('img1').src = window.URL.createObjectURL(convertBlobToBase64(xhr.responseText));
    }

    xhr.send(formData);
}

document.getElementById('postNameForm').addEventListener('submit', postName);

function postName(e){
    e.preventDefault();
    var file = document.getElementById('file1').files[0];
    var name = document.getElementById('name2').value;
    var parameters = "name="+name;

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'http://localhost:8008/process.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');

    xhr.onload = function() {
        console.log(this.responseText)
    }

    xhr.send(parameters);
}

function loadUsers(){
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'http://localhost:8008/users.php', true);

    var output = '';

    xhr.onload = function() {
        if (this.status == 200) {
            var users = JSON.parse(this.responseText);

            for (var i in users) {
                output += '<ul>' +
                '<li>ID: ' + users[i].id + "</li>" +
                '<li>Name: ' + users[i].name + "</li>" +
                '</ul>';
            }

            document.getElementById('resultDiv').innerHTML = output;
        }
    }

    xhr.send();
}
==> ./ajax005/resources/myfile.js <==
document.getElementById('myButton').addEventListener('click', loadText);

function loadText(){
    //Create XHR object
    var xhr = new XMLHttpRequest();
    // OPEN - type, url/file, async
    console.log(xhr);
    xhr.open('GET', 'words.txt', true);

    console.log('READYSTATE: ', xhr.readyState);
    //onload only operates on readyState = 4
    xhr.onload = function() {
        if(this.status == 200) {
            document.getElementById('text').innerHTML = this.responseText;
        } else if(this.status == 404) {
            document.getElementById('text').innerHTML = "Not found";
        } else {
            document.getElementById('text').innerHTML = "Error";
        }
        console.log(xhr);
    }

    xhr.onerror = function() {
        console.log("Request error");
    }

    // readyState Values
    // 0: request not initialized
    // 1: server connection established
    // 2: request received
    // 3: processing request
    // 4: request finished and response is ready
    xhr.onreadystatechange = function() {
        if(this.readyState != 4) {
            /*do spinny cursor*/
        }
    }

    // Sends request
    xhr.send();
}
