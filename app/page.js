// "use client"
// import Image from "next/image";
// import { useState } from "react";
// import { runCppProgram } from "@/server/axiosModule";
// import Button from "@/components/Button"

// export default function Home() {

//   const [output, setOutput] = useState("Click Me");

//   const handleClick = async () => {
//     //try
//     const result = await runCppProgram();
//     setOutput(result);
//     //catch error here
//   }
//   return (
//     <div className="flex items-center justify-center min-h-screen">
//       <Button onClick={handleClick} label={output} />
//     </div>
//   );
// }
// pages/index.js
// pages/index.js

import Image from 'next/image';
import Link from 'next/link';

export default function Home() {
  return (
    <div className="min-h-screen bg-gray-900 text-white font-serif">
      {/* Header */}
      <header className="flex justify-between items-center p-6 bg-gray-800 shadow-md">
        <div className="text-2xl font-bold flex items-center">
          <Image
            src="/flashcard.png"
            alt="Logo"
            width={40}
            height={40}
          />
          <span className="ml-2">Testy</span>
        </div>
        <nav className="flex space-x-6">
          <Link href="/about" className="text-lg hover:text-blue-400 py-2 px-4">
            About
          </Link>
          <Link href="/profile" className="text-lg hover:text-blue-400 py-2 px-4">
            My profile
          </Link>
          <Link href="/my-sets" className="text-lg bg-green-600 text-white py-2 px-4 rounded hover:bg-green-700">
            Study sets
          </Link>
        </nav>
      </header>

      {/* Main section */}
      <main className="flex flex-col items-center justify-center py-20 text-center">
        <h1 className="text-4xl font-bold mb-4">Are you ready to ace your next exam?</h1>
        <p className="text-lg text-gray-400 mb-8">
          Testy is an open-source study guide creator application. Tailored to your academic needs.
        </p>
        <button className="bg-blue-800 text-white py-3 px-8 rounded-full text-xl transform transition-transform duration-300 hover:scale-105 hover:bg-blue-600">
          Start Studying
        </button>
      </main>

      {/* Info section */}
      <section className="py-16 bg-gray-800">
        <div className="max-w-5xl mx-auto flex flex-col md:flex-row items-center">
          <div className="md:w-1/2 mb-8 md:mb-0">
            <h2 className="text-3xl font-bold mb-4">Here&apos;s How it Works:</h2>
            <ul className="list-disc list-inside text-lg space-y-2">
              <li>Create study sets specific to your subject</li>
              <li>Save and edit your study sets for later use</li>
              <li>Generate quizzes off of your previously created sets to enhance your study session</li>
            </ul>
          </div>
          <div className="md:w-1/2 flex justify-center ">
            <Image
              src="/studyimage.PNG"
              alt="Illustration of studying (royalty free)"
              width={350}
              height={350}
              className="rounded-lg"
            />
          </div>
        </div>
      </section>

      {/* Card section */}
      <section className="py-16 bg-gray-900">
        {/*grid container */}
        <div className="max-w-6xl mx-auto grid grid-cols-2 md:grid-cols-2 gap-12">
        {/*second card image */}
        <div className="bg-gray-800 p-6 rounded-lg shadow-lg flex flex-col justify-between transform transition-transform duration-300 hover:scale-105">
            <Image
              src="/flashcard.png"
              alt="Class material illustration"
              width={400}
              height={200}
              className="rounded-lg"
            />
          </div>

          {/* first card text*/}
          <div>
            <h2 className="mt-4 text-2xl font-bold">Make class material instantly studiable</h2>
              <p className="text-gray-400 mt-2">
                Turn your notes into flashcards, practice quizzes, and study guides. You got this.
              </p>
              <button className="mt-4 bg-blue-800 text-white py-2 px-6 rounded transform transition-transform duration-300 hover:scale-105 hover:bg-blue-600">
                Try it out
              </button>
          </div>
          {/* second card text*/}
          <div>
            <h2 className="mt-4 text-2xl font-bold">Instantly improve understanding</h2>
              <p className="text-gray-400 mt-2">
                  Memorize anything with personalized practice tests. No exam stands a chance.
              </p>
              <button className="mt-4 bg-blue-800 text-white py-2 px-6 rounded transform transition-transform duration-300 hover:scale-105 hover:bg-blue-600">
                Get started
              </button>
          </div>
          {/*second card image */}
          <div className="bg-gray-800 p-6 rounded-lg shadow-lg flex flex-col justify-between transform transition-transform duration-300 hover:scale-105">
            <Image
              src="/books.png" // Replace with the actual image path
              alt="Class material illustration"
              width={400}
              height={200}
            />
          </div>
        </div>
      </section>

      <section className="py-16 bg-gray-800 mb-20">
        <div className="max-w-5xl mx-auto flex flex-col md:flex-row items-center">
          <div className="md:w-1/2 mb-8 md:mb-0">
            <h2 className="text-3xl font-bold mb-4">Who is Testy for?</h2>
            <p className="text-zinc-100 text-lg">
            Testy is for anyone looking to enhance their learning experience, from students in middle school, high school, or college to teachers seeking to create engaging classroom materials.
             It also caters to self-learners who want to master new topics and professionals preparing for exams or certifications.
            With tools that support various learning styles, Quizlet makes studying more interactive, efficient, and tailored to individual needs. Now what are you waiting for? Start studying!
            </p>
          </div>
        </div>
      </section>

      {/* Footer */}
      <footer className="text-center py-4 border-t border-gray-700">
        <p>© 2024 Testy.</p>
        <a href="#top" className="text-gray-400">Back to the top</a>
      </footer>
    </div>
  );
}
