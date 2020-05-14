open UseFetch;

let mainStyle = ReactDOMRe.Style.make(
  ~border="1px solid #48a9dc",
  ~borderRadius="5px",
  ~padding="10px",
  ~display="inline-block",
  ~minWidth="100px",
  ()
);

let cityStyle = ReactDOMRe.Style.make(
  ~display="block",
  ~margin="0",
  ~padding="0",
  ~fontSize="20px",
  ~color="#48a9dc",
  ()
);

let conditionStyle = ReactDOMRe.Style.make(
  ~padding="10px 0 10px 0",
  ~color="#717171",
  ~fontSize="14px",
  ~display="inline-block",
  ()
);

let tempStyle = ReactDOMRe.Style.make(
  ~padding="10px 0 10px 0",
  ~color="#717171",
  ~fontSize="14px",
  ()
);

[@react.component]
let make = (~city: string, ~condition: string, ~temp: string) => {
  let url = "http://api.weatherapi.com/v1/current.json?key=955044fede38469c925103318201405&q=" ++ city;
  let response = useFetch(url);

  switch(response) {
    | LoadingWeatherInfo => <div>{React.string("Loading weather info")}</div>
    | ErrorLoadingWeatherInfo => <div>{React.string("Failed to load it")}</div>
    | LoadedWeatherInfo(temp, condition) => {
        <div style={mainStyle}>
          <h1 id="cityName" style={cityStyle}>{React.string(city)}</h1>
          <div style={conditionStyle}>{React.string(condition)}</div>
          <span style={tempStyle}>{React.string(" - " ++ string_of_int(temp))}</span>
        </div>
    }
  }
}
