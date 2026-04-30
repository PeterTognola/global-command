import type {FC} from "react";
import type {Result} from "../App.tsx";

interface Props {
    result: Result;
}

export const ResultComponent: FC<Props> = ({ result }) => {
    const select = () => {
        // todo handle actions.
        // todo handle open programs.

        alert("Action: An action or program will be executed.");
    };

    return <div onClick={select} style={{backgroundColor: "rgba(255, 255, 255, 0.7)", borderRadius: "16px", padding: "8px 8px", marginTop: "4px", display: "flex", verticalAlign: "middle", flex: 1, flexDirection: "row", columnGap: "6px"}}>
        <span className={"icon"} style={{width: "20px", height: "20px", backgroundColor: "red", display: "block", borderRadius: "16px"}} />
        <h3 style={{margin: 0}}>{result.name}</h3>
    </div>;
}