import "./styles.css";
import React from "react";
import { useState } from "react";
import { useEffect } from "react";

export default function App() {
  const [input, setInput] = useState();
  const [recipes, showRecipes] = useState([]);
  const fetchdata = async () => {
    const data = await fetch(`https://dummyjson.com/recipes/search?q=${input}`);
    const json = await data.json();
    showRecipes(json?.recipes);
  };
  useEffect(() => {
    fetchdata();
  }, [input]);

  return (
    <div className="App">
      <div>
        <h1>Autocompletet serachbar</h1>
      </div>
      <input
        type="text"
        className="search"
        value={input}
        onChange={(e) => {
          setInput(e.target.value);
        }}
      />
      <div className="results">
        {recipes.map((item) => (
          <div key={item.id} className="recipe">
            <h3>{item.name}</h3>
            <p>
              <strong>Cuisine:</strong> {item.cuisine}
            </p>
          </div>
        ))}
      </div>
    </div>
  );
}
