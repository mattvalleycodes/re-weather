type t = {
  key: string,
  value: string,
};

let clean = (source) => {
  switch(Js.String2.charAt(source, 0)) {
    | "?" => Js.String2.substr(source, ~from=1);
    | _ => source;
  }
};

let qs = (source) => {
  switch(source) {
    | "" => [||];
    | _ => {
      source
        -> Js.String2.trim
        -> clean
        -> Js.String2.split("&")
        -> Js.Array2.map((kv) => {
          switch(Js.String2.split(kv, "=")) {
            | [|"", ""|] => { key: "", value: ""};
            | [|k, ""|] => { key: k, value: ""};
            | [|k, v|] => { key: k, value: v};
            | _ => { key: "", value: ""};
          }
        });
    };
  }
}
