import React, { useEffect, useState } from "react";
import "./Weather.css";

function Weather() {
  const [city, setCity] = useState(null);
  const [search, setSearch] = useState("Lucknow");

  useEffect(() => {
    const fetchAPI = async () => {
      const url = `http://api.openweathermap.org/data/2.5/weather?q=${search}&units=metric&appid=42b52f10f6026611871cdaa51836aca9`;
      const response = await fetch(url);
      const resJson = await response.json();
      // console.log(resJson)
      setCity(resJson.main);
    };

    fetchAPI();
  }, [search]);

  return (
    <div className="box">
      <div className="search__box">
        <input
          type="search"
          value={search}
          className="input__field"
          onChange={(events) => {
            setSearch(events.target.value);
          }}
        />
      </div>

      {!city ? (
        <p className="errorMsg"> Please, Enter a City! </p>
      ) : (
        <div>
          <div className="details">
            <h2 className="loaction__name">
              <i className="fas fa-street-view"></i>
              {search}
            </h2>
            <h1 className="temp__value">{city.temp} Cel</h1>
            <h3 className="temp__valueMM">
              Min : {city.temp_min} Cel | Max : {city.temp_max} Cel
            </h3>
          </div>

          <div className="wave -one"></div>
          <div className="wave -two"></div>
          <div className="wave -three"></div>
        </div>
      )}
    </div>
  );
}

export default Weather;
