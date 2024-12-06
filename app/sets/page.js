"use client"
import React from 'react'
import NavBar from '@/components/NavBar';
import { useState, useEffect } from 'react';
import Link from 'next/link';
import { getData } from '@/server/axiosModule';



const Sets = () => {
    //list of cards in a set
    const [mySet, setMySet] = useState([]);
    //list of all existing sets (array of objects)
    const [possibleSets, setPossibleSets] = useState([])
    const [nameCounter, setNameCounter] = useState(1);
    const [currentSet, setCurrentSet] = useState()

    // Function to fetch data or populate state
    // const fetchData = async () => {
    //     // Example data fetching or initialization logic
    //     const response = await getData();
    //     const allCards = response.output;
    //     let localSets = []

    //     for (let i=0; i < allCards.length; i+=3) {
    //         let obj = {
    //             front: [allCards[i]],
    //             back: [allCards[i+1]],
    //             id: [allCards[i+2]]
    //         }
    //         let setFound = false;

    //         // Iterate through all the existing sets
    //         for (let set of possibleSets) {
    //             if (obj.id === set.setId) {
    //                 set.cards.push(obj); // Push to the respective set
    //                 console.log("set already exists");
    //                 setFound = true;
    //                 break; // Exit the loop once a match is found
    //             }
    //         }
    
    //         // If no set was found, create a new set

    //         if (!setFound) {
    //                 const newSet = {
    //                     name: `My Set: ${updatedCount}`,
    //                     cards: [obj],
    //                     setId: obj.id,
    //                 }
    //                 setNameCounter(prev => {
    //                     const updatedCount = prev+1;
    //                     setPossibleSets(prevState => [...prevState, {newSet}]);
    //                     return updatedCount;
    //             })
    //             localSets.push(newCount);
    //         }
    //     }
    // }

//     const newSet = (obj, updatedSets) => {
//         // Increment nameCounter and use the updated value for the set name
//             const updatedCount = nameCounter+1;
//             const newSetObj = {
//                 name: `My Set: ${updatedCount}`,
//                 cards: [obj],
//                 setId: obj.id,
//             };
//             return updatedCount;
//         updatedSets.push(newSetObj); // Update the local array
//         console.log("create new set", newSetObj);
//     };
// }



    const fetchData = async () => {
        const response = await getData();
        const allCards = response.output;

        // Work with a local copy of possibleSets
        const updatedSets = [...possibleSets];
        let counter = 1;
        let character = ' ';
        for (let i = 0; i < allCards.length; i += 3) {
            let obj = {
                front: allCards[i].replace(/_/g, character),
                back: allCards[i + 1].replace(/_/g, character),
                id: allCards[i + 2],
            };
            let setFound = false;

            // Check for existing sets in the local copy
            for (let set of updatedSets) {
                // console.log(`CardID: ${obj.id}`);
                // console.log(`CardID: ${set.setId}`);
                if (obj.id == set.setId) {
                    set.cards.push(obj); // Push to the respective set
                    console.log("set already exists");
                    setFound = true;
                    break;
                }
            }

            // If no set was found, create a new one
            if (!setFound) {
                console.log("creating a new set");
                const newSetObj = {
                    name: `My Set: ${counter}`,
                    cards: [obj],
                    setId: obj.id,
                };
                console.log(newSetObj);
                counter += 1;
                updatedSets.push(newSetObj); // Update the local array
            }
        }

        // Update the state once after processing all sets
        setPossibleSets(updatedSets);
        setNameCounter(counter);
    };

    // Run fetchData once every time the page loads
    useEffect(() => {
        fetchData();
    }, []); // Empty dependency array ensures it runs only on mount

    

    const handleSelectSet = (name) => {
        //selects what card 
        setCurrentSet(name);
        for(let set of possibleSets) {
            if (set.name === name) {
                //display cards of this set
                setMySet(set.cards);
            }
        }

      };
    
  return (
    <>
    <NavBar/>
        <div className="min-h-screen flex flex-col items-center  bg-gray-900">
            <div className="mt-6 w-80">
            {mySet.length > 0 ? (
                <h2 className="text-lg text-white font-semibold mb-4">{currentSet}</h2>
            ) : (
                <></>
            )}
                <div className="grid grid-cols-[repeat(auto-fill,_minmax(120,_1fr))] gap-6">
                    {mySet.length > 0 ? (
                    mySet.map((data, index) => (
                        <div
                        key={index}
                        // className="p-6 bg-gray-800 rounded-lg shadow-md hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform"
                        className="text-black min-w-10 bg-gray-200 px-4 mb-3 rounded shadow-inner word-wrap"
                        >
                        <p>
                            <strong>{data.front}</strong>
                        </p>
                        <p className="text-black overflow-auto break-words">
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
                    possibleSets.map((set, index) => (
                        <div
                        key={index}
                        // className="p-6 bg-gray-800 rounded-lg shadow-md hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform"
                        className=""
                        >
                        <button className=" text-black min-w-20 bg-gray-200 py-2 px-7 mb-3 rounded shadow-inner hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform" 
                        onClick={() => handleSelectSet(set.name)}>{set.name}</button>
                        </div>
                    ))
                    ) : (
                    <p className="text-gray-500">No sets yet.</p>
                    )}
                </div>
            </div>
            <Link href="/study" className="text-black min-w-20 bg-blue-200 py-2 px-7 my-20 rounded shadow-inner hover:scale-105 hover:shadow-2xl hover:brightness-110 transition-transform">Make a New Set</Link>
        </div>
    </>
  )}


 export default Sets;

