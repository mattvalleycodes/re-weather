type city = {
  name: string,
  temp: string,
  condition: string
};

let cities = [
  { name: "Sydney", temp: "14", condition: "Cloudy" },
  { name: "San Fransico", temp: "10", condition: "Sunny" },
  {name: "Tehran", temp: "20", condition: "Rainy" }
];

let citiesStyle = ReactDOMRe.Style.make(
  ~listStyle="none",
  ~padding="0",
  ~margin="0",
  ()
);

let cityStyle = ReactDOMRe.Style.make(
  ~margin="0 0 10px 0",
  ()
);

let toWeather = (c: city) => {
  <li style={cityStyle}>
    <Weather city={c.name} condition={c.condition} temp={c.temp} />
  </li>

};

[@react.component]
let make = () => {
  let source = List.map(toWeather, cities);

  <ul style={citiesStyle}>{React.array(Array.of_list(source))}</ul>
};
