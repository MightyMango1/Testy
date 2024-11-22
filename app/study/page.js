"use client"
import React from 'react'
import Image from 'next/image';
import Link from 'next/link';
import NavBar from '@/components/NavBar';
import { useState } from "react";
import { addCards } from "@/server/axiosModule";


const studyPage = () => {
  const [textBox1, setTextBox1] = useState("");
  const [textBox2, setTextBox2] = useState("");
  const [submittedData, setSubmittedData] = useState([]);

  const handleSubmit = (e) => {
    e.preventDefault();
    setSubmittedData([...submittedData, { textBox1, textBox2 }]);
    setTextBox1(""); // Clear the inputs
    setTextBox2("");
  };

  const handleSubmitDeck = async (e) => {
    //try
    const result = await addCards(submittedData);
    alert(result);
  }

  return (
    <>
    <NavBar />
    <div className="min-h-screen flex flex-col items-center justify-center bg-gray-900">

      <h1 className="text-2xl font-bold mb-6">Input Form</h1>
      <form
        onSubmit={handleSubmit}
        className="bg-gray-700 p-6 rounded shadow-md w-80 space-y-2"
      >
        <h1 className="text-white font-serif text-lg">Front of Card:</h1>
        <textarea
          className="w-full p-2 border text-black border-gray-300 rounded resize-none"
          rows="5"
          value={textBox1}
          onChange={(e) => setTextBox1(e.target.value)}
          placeholder="Enter text for flashcard front"
        />
        <h1 className="text-white text-lg font-serif">Back of Card:</h1>
        <textarea
          className="w-full p-2 border text-black border-gray-300 rounded resize-none"
          rows="5"
          value={textBox2}
          onChange={(e) => setTextBox2(e.target.value)}
          placeholder="Enter text for flashcard back"
        />
        <button
          type="submit"
          className="w-full bg-blue-500 text-white py-2 rounded hover:bg-blue-600"
        >
          Add Card
        </button>
      </form>

      <div className="mt-6 w-80">
        <h2 className="text-lg font-semibold mb-4">My Flashcards:</h2>
        {submittedData.length > 0 ? (
          submittedData.map((data, index) => (
            <div
              key={index}
              className="bg-gray-200 text-black p-3 mb-3 rounded shadow-inner word-wrap"
            >
              <p>
                <strong>{data.textBox1}</strong>
              </p>
              <p className="text-black overflow-auto break-words">
                {data.textBox2}
              </p>
            </div>
          ))
        ) : (
          <p className="text-gray-500">No data submitted yet.</p>
        )}

        <button
          type="submit"
          className="w-full bg-green-500 text-white my-4 py-4 rounded hover:bg-green-600"
          onClick={handleSubmitDeck}
        >
          Submit Deck
        </button>
      </div>
      
    </div>
    </>
  );
}

export default studyPage;
