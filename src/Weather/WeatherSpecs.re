open BsMocha;
open Mocha;
open Enzyme;
open Enzyme.Shallow;
open BsChai.Expect.Expect;
open BsChai.Expect.Combos.End;

configureEnzyme(react_16_adapter());

describe("<Weather />", () => {
  it("example of pure Chai assertion", () =>
    expect(1 + 1) |> to_equal(2)
  );

  it("includes the city information", () => {
    let weather = shallow(<Weather city="Sydney" temp="20" condition="Cloudy" />);
    let city = weather |> find("h1") |> text;
    let condition = weather |> find("div") |> at(1) |> text;
    let temp = weather |> find("span") |> text;


    expect(city) |> to_equal("Sydney")
    expect(temp) |> to_include("20");
    expect(condition) |> to_equal("Cloudy");
  });
});
