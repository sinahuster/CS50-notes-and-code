# CS50 Week 8 - HTML, CSS & Javascript 

## Topics Covered
- HTML (HyperText Markup Language)
- CSS (Cascading Style Sheets)
- JavaScript (Client-Side Scripting)
- DOM (Document Object Model)
- Event Handling
- Local Storage
- Asynchronous JavaScript (fetch, APIs)
- Progressive Enhancement & Accessibility

## HTML

HTML structes the content of web pages.
Basic Structure:
```
<!DOCTYPE html>
<html lang="en">
  <head>
    <title>My Page</title>
  </head>
  <body>
    <h1>Hello, World!</h1>
    <p>This is a paragraph.</p>
    <a href="https://cs50.harvard.edu">CS50</a>
  </body>
</html>
```
Common Elements:
- Headings: ```<h1> ... <h6>```
- Paragraphs: ```<p>```
- Links: ```<a href = "">```
- Lists: ```<ul>```, ```<ol>```, ```<li>```
- Forms: ```<form>```, ```<input>```, ```<button>```

Image
```
<!DOCTYPE html>

<!-- Demonstrates image -->

<html lang="en">
    <head>
        <title>image</title>
    </head>
    <body>
        <img alt="photo of bridge" src="bridge.png">
    </body>
</html>
```
The same can be done for videos.

Google search
```
<!DOCTYPE html>

<!-- Demonstrates additional form attributes -->

<html lang="en">
    <head>
        <title>search</title>
    </head>
    <body>
        <form action="https://www.google.com/search" method="get">
            <input autocomplete="off" autofocus name="q" placeholder="Query" type="search">
            <button>Google Search</button>
        </form>
    </body>
</html>
```

## CSS

CSS styles the apperance of HTML.

Selectors
```
h1 {
  color: blue;
  text-align: center;
}
p {
  font-size: 16px;
}
```
Ways to use CSS
1. Inline (```style="color:red;"```)
2. Internal (```<style>...</style>```)
3. External (```<link rel="stylesheet" href="style.css">```)

CSS can be used in HTML as follows:
```
<!DOCTYPE html>

<!-- Uses semantic tags instead of DIVs -->

<html lang="en">
    <head>
        <title>css</title>
    </head>
    <body style="text-align: center">
        <header style="font-size: large">
            John Harvard
        </header>
        <main style="font-size: medium">
            Welcome to my home page!
        </main>
        <footer style="font-size: small">
            Copyright &#169; John Harvard
        </footer>
    </body>
</html>
```

A CSS file could look as follows:
```
.centered
{
    text-align: center;
}

.large
{
    font-size: large;
}

.medium
{
    font-size: medium;
}

.small
{
    font-size: small;
}
```
Then it can be acessed from a HTML file as follows
```
<!DOCTYPE html>

<!-- Demonstrates external stylesheets -->

<html lang="en">
    <head>
        <link href="style.css" rel="stylesheet">
        <title>css</title>
    </head>
    <body class="centered">
        <header class="large">
            John Harvard
        </header>
        <main class="medium">
            Welcome to my home page!
        </main>
        <footer class="small">
            Copyright &#169; John Harvard
        </footer>
    </body>
</html>
```

## Javascript

Javascript makes the web page interactive.

Basic Example
```
<script>
  document.querySelector("button").onclick = function() {
    alert("Button clicked!");
  };
</script>
```

Conditions and Loops 
```
if (name === "Alice") {
  console.log("Hello, Alice!");
}

for (let i = 0; i < 5; i++) {
  console.log(i);
}
```
The following autocompletes text: 
```
<!DOCTYPE html>

<html lang="en">

    <head>
        <title>autocomplete</title>
    </head>

    <body>

        <input autocomplete="off" autofocus placeholder="Query" type="text">

        <ul></ul>

        <script src="large.js"></script>
        <script>
      
            let input = document.querySelector('input');
            input.addEventListener('keyup', function(event) {
                let html = '';
                if (input.value) {
                    for (word of WORDS) {
                        if (word.startsWith(input.value)) {
                            html += `<li>${word}</li>`;
                        }
                    }
                }
                document.querySelector('ul').innerHTML = html;
            });

        </script>

    </body>
</html>
```
It pulls from a file called ```large.js``` which is a list of words. 


## DOM 

The DOM represents the structure of a webpage as objects.

Selecting Elements:
```
document.querySelector("h1").innerHTML = "Changed!";
document.querySelectorAll("p");
```

```DOMContentLoaded``` ensures that the whole page is loaded before executing the JavaScript.
```
<!DOCTYPE html>

<!-- Demonstrates DOMContentLoaded -->

<html lang="en">
    <head>
        <script>

            document.addEventListener('DOMContentLoaded', function() {
                document.querySelector('form').addEventListener('submit', function(e) {
                    alert('hello, ' + document.querySelector('#name').value);
                    e.preventDefault();
                });
            });

        </script>
        <title>hello</title>
    </head>
    <body>
        <form>
            <input autocomplete="off" autofocus id="name" placeholder="Name" type="text">
            <input type="submit">
        </form>
    </body>
</html>
```

## Event Handling

Responding to user interaction
```
document.querySelector("#myButton").addEventListener("click", function() {
  document.querySelector("#output").innerHTML = "Button pressed!";
});
```

## Local Storage 

Stores data in the browser (persists after reload).
```
localStorage.setItem("username", "Alice");
let user = localStorage.getItem("username");
console.log(user); // Alice
```

## Asynchronous Javascript

Fetching data from APIs
```
fetch("https://api.example.com/data")
  .then(response => response.json())
  .then(data => console.log(data));
```

## Accessibilty and Progress Enhanchment

- Use semantic HTML (```<header>```, ```<footer>```, ```<nav>```)
- Add ```alt``` attributes to images
- Ensure pages still work if JS/CSS doesn’t load
- Use ARIA roles sparingly, prefer built-in semantics

- ## Code Descriptions 

1. table.html - demonstates how to create a table in HTML. 

2. search.html - demonstrates how to create a search box in HTML. 

3. register.html - demonstrates registration of an email which requires a certain format in order to be accepted in HTML 

4. link.html - demonstates how to add a link in HTML. 

5. hello.html - demonstrates the use of Javascript to make a webpage intereactive. 

6. trivia - created one multiple choice question and one open ended question using HTML, CSS and Javascript. 

7. homepage - created an extremely basic personal webpage containing four different HTML pages, ten HTML tags, a feature from Bootstrap,
              five CSS selectors, and an interative feature from Javascript. 
