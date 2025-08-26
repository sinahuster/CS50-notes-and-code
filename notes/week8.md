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
<html>
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

## DOM 

The DOM represents the structure of a webpage as objects.

Selecting Elements:
```
document.querySelector("h1").innerHTML = "Changed!";
document.querySelectorAll("p");
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

