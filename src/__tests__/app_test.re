open Jest;

open ExpectJs;

let _ =
  describe
    "src/app.re"
    (
      fun _ => {
        test
          "is defined"
          (
            fun _ => {
              let component = ReactShallowRenderer.renderWithRenderer <ChuckNorrisApp />;
              expect (Js.Undefined.return component) |> toBeDefined
            }
          );
        test
          "renders"
          (
            fun _ => {
              let tree = <ChuckNorrisApp /> |> ReactShallowRenderer.renderWithRenderer;
              expect tree |> toMatchSnapshot
            }
          )
      }
    );
