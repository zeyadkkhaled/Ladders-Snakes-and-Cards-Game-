#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
//when adding other cards' classes remove the comment
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
//#include "CardTen.h"
//#include "CardEleven.h"
//#include "CardTwelve.h"





AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardNumber" parameter and set its data member
		pOut->PrintMessage("New card: type card number between 1 and 12 ...");
		cardNumber =pIn->GetInteger(pOut);
		
		if (cardNumber <= 0 || cardNumber > 12) {
			pGrid->PrintErrorMessage("Error:Entered card number must be between 1 and 12! Click to continue ...");
			cardPosition = CellPosition(-1, -1);
			return;
		}
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
		pOut->PrintMessage("New card: click on card cell ...");
		cardPosition = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
		
		
			if (cardPosition.IsValidCell() != true) {
				pGrid->PrintErrorMessage("Error:Cell is invalid! Click to continue ...");
				cardPosition = CellPosition(-1, -1);
				return;
			}
			else if (pGrid->GetCellFromCellPosition(cardPosition)->HasCard() != NULL) {
				pGrid->PrintErrorMessage("Error: card already has a card! Click to continue ...");
				cardPosition = CellPosition(-1, -1);
				return;
			}
			else if (pGrid->GetCellFromCellPosition(cardPosition)->HasLadder() != NULL) {
				pGrid->PrintErrorMessage("Error:This Cell is the start of a ladder! Click to continue ...");
				cardPosition = CellPosition(-1, -1);
				return;
			}
			else if (pGrid->GetCellFromCellPosition(cardPosition)->HasSnake() != NULL) {
				pGrid->PrintErrorMessage("Error:This Cell is the start of a snake! Click to continue ...");
				cardPosition = CellPosition(-1, -1);
				return;
			}
		
		
	// 5- Clear status bar
		pOut->ClearStatusBar();

}

void AddCardAction::Execute() 
{

	// 1- The first line of any Action Execution is to read its parameter first
		ReadActionParameters();
		if (cardPosition.HCell() == -1 || cardPosition.VCell() == -1  ) return;
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
		//when adding other cards' classes remove the comment
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);

		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
	break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	// case 10:
	//	pCard = new CardTen(cardPosition);
	//	break;
	//case 11:
	//	pCard = new CardEleven(cardPosition);
	//	break;
	//case 12:
	//	pCard = new CardTwelve(cardPosition);
	//	break;



	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		if (!(pCard->CheckInputValidity())) //checks the validity of entered card parameters (to be implemented) 
		{
			delete pCard;
			pCard = NULL;
		}
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
