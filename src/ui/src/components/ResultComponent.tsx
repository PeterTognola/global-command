import type {FC} from "react";
import type {Result} from "../App.tsx";

interface Props {
    result: Result;
}

export const ResultComponent: FC<Props> = ({ result }) => {
    return <div>
        <span className={"icon"} />
        <h3>{result.name}</h3>
    </div>;
}