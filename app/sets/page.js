"use client"
import React from 'react'
import NavBar from '@/components/NavBar';
import { useState } from 'react';
import Link from 'next/link';

const Sets = () => {
    //list of all cards in the set
    const [mySet, setSet] = useState([
        {front: "Test1", back: "This is a test definition for a card object"},
        {front: "Test1", back: "Test2"},
        {front: "Test1", back: "Test2"},
        {front: "Test1", back: "Test2"}]);

    //list of all existing sets
    const [possibleSets, setPossibleSets] = useState([
        {name: "Set1"},
        {name: "Set2"}
    ]);

    const [currentSet, setCurrentSet] = useState({name: "Set1"})

    const handleClick = (e) => {
        e.preventDefault();
        //change mySet to the button pressed
      };
    
  return (
    <>
    <NavBar/>
        <div className="min-h-screen flex flex-col items-center  bg-gray-900">
            <div className="mt-6 w-80">
            {mySet.length > 0 ? (
                <h2 className="text-lg text-white font-semibold mb-4">{currentSet.name}</h2>
            ) : (
                <></>
            )}
                <div className="grid grid-cols-[repeat(auto-fill,_minmax(120,_1fr))] gap-6">
                    {mySet.length > 0 ? (
                    mySet.map((data, index) => (
                        <div
                        key={index}
                        // className="p-6 bg-gray-800 rounded-lg shadow-md hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform"
                        className="min-w-10 bg-gray-200 px-4 mb-3 rounded shadow-inner word-wrap"
                        >
                        <p>
                            <strong>{data.front}</strong>
                        </p>
                        <p className="overflow-auto break-words">
                            {data.back}
                        </p>
                        </div>
                    ))
                    ) : (
                    <p className="text-gray-500">No Flashcards in this set.</p>
                    )}
                </div>
            </div>
            <div className="mt-6 w-80">
                <h2 className="text-lg text-white font-semibold mb-4">My Sets:</h2>
                <div className="grid grid-cols-[repeat(auto-fill,_minmax(120,_1fr))] gap-6">
                    {possibleSets.length > 0 ? (
                    possibleSets.map((data, index) => (
                        <div
                        key={index}
                        // className="p-6 bg-gray-800 rounded-lg shadow-md hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform"
                        className=""
                        >
                        <button className="min-w-20 bg-gray-200 py-2 px-7 mb-3 rounded shadow-inner hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform" 
                        onClick={handleClick}>{data.name}</button>
                        </div>
                    ))
                    ) : (
                    <p className="text-gray-500">No sets yet.</p>
                    )}
                </div>
            </div>
            <Link href="/study" className="min-w-20 bg-blue-200 py-2 px-7 my-20 rounded shadow-inner hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform">Make a New Set</Link>
        </div>
    </>
  )
}

 export default Sets;

