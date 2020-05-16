/*open Jest;
open Expect;
open Enzyme;
open Enzyme.Shallow;

configureEnzyme(react_16_adapter());

describe("<Weather />", () => {
  test("example of pure Jest assertion", () =>
    expect(1 + 1) |> toBe(2)
  );

  test("includes the city information", () => {
    let weather = shallow(<Weather city="Sydney" temp="20" condition="Cloudy" />);
    let city = weather |> find("h1") |> text;
    let condition = weather |> find("div") |> at(1) |> text;
    let temp = weather |> find("span") |> text;

    expect(city) |> toEqual("Sydneyy");
    expect(temp) |> toEqual("21");
    expect(condition) |> toEqual("Cloudy");
  });
});*/
