import React, { useState, useEffect } from 'react'
import utils from '../math-utils'

import PlayAgain from './PlayAgain'
import PlayNumber from './PlayNumber'
import StarsDisplay from './StarsDisplay'

const useGameState = () => {
  const [stars, setStars] = useState(utils.random(1, 9))
  const [availableNums, setAvailableNums] = useState(utils.range(1, 9))
  const [candidateNums, setCandidateNums] = useState([])
  const [secondsLeft, setSecondsLeft] = useState(10)

  useEffect(() => {
    if (secondsLeft > 0 && availableNums.length > 0) {
      const timerId = setTimeout(() => setSecondsLeft(secondsLeft - 1), 1000)
      return () => clearTimeout(timerId)
    }
  })

  const setGameState = (newCandidates) => {
    setCandidateNums(newCandidates)

    if (utils.sum(newCandidates) === stars) {
      const newAvailable = availableNums.filter(
        (n) => !newCandidates.includes(n)
      )
      setAvailableNums(newAvailable)
      setStars(utils.randomSumIn(newAvailable, 9))
      setCandidateNums([])
    }
  }

  return {
    stars,
    availableNums,
    candidateNums,
    secondsLeft,
    setGameState,
  }
}

const Game = (props) => {
  const {
    stars,
    availableNums,
    candidateNums,
    secondsLeft,
    setGameState,
  } = useGameState()

  const candidatesAreWrong = utils.sum(candidateNums) > stars
  const gameStatus =
    availableNums.length === 0 ? 'won' : secondsLeft === 0 ? 'lost' : 'active'

  const numberStatus = (number) => {
    if (!availableNums.includes(number)) {
      return 'used'
    }
    if (candidateNums.includes(number)) {
      return candidatesAreWrong ? 'wrong' : 'candidate'
    }
    return 'available'
  }

  const onNumberClick = (number, status) => {
    if (gameStatus !== 'active' || status === 'used') {
      return
    }

    const newCandidates =
      status === 'available'
        ? [...candidateNums, number]
        : candidateNums.filter((candidate) => candidate !== number)

    setGameState(newCandidates)
  }

  return (
    <div className="game">
      <div className="help">
        Pick 1 or more numbers that sum to the number of stars{' '}
      </div>{' '}
      <div className="body">
        <div className="left">
          {' '}
          {gameStatus !== 'active' ? (
            <PlayAgain status={gameStatus} onClick={props.startNewGame} />
          ) : (
            <StarsDisplay count={stars} />
          )}{' '}
        </div>{' '}
        <div className="right">
          {' '}
          {utils.range(1, 9).map((number) => (
            <PlayNumber
              key={number}
              status={numberStatus(number)}
              onClick={onNumberClick}
              number={number}
            />
          ))}{' '}
        </div>{' '}
      </div>{' '}
      <div className="timer"> Time Remaining: {secondsLeft} </div>{' '}
    </div>
  )
}

export default Game
