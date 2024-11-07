"use client"
import Image from "next/image";
import { useState } from "react";
import { runCppProgram } from "@/server/axiosModule";
import Button from "@/components/Button"

export default function Home() {

  const [output, setOutput] = useState("Click Me");

  const handleClick = async () => {
    //try
    const result = await runCppProgram();
    setOutput(result);
    //catch error here
  }
  return (
    <div className="flex items-center justify-center min-h-screen">
      <Button onClick={handleClick} label={output} />
    </div>
  );
}
