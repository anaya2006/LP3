 pragma solidity ^0.8.20;

contract BankAccount{

    address public owner;

    constructor()
    {
        owner= msg.sender;
    }

    //Deposit ether from the bank account
    function deposit() public payable   //payable allows the function to recieve ether
    {
        require(msg.value >0, "Deposit amount must be greater than 0");
    }

    //Withdraw ether from the bank account
    function withdraw(uint256 amount)public 
    {
        require(msg.sender == owner, "Only account owner can withdraw.");
        require(amount>0,"Amount must be greater than 0");
        require(address(this).balance >= amount,"Insufficient balance");

        (bool success, ) = payable(msg.sender).call{value: amount}("");
require(success, "Transfer failed");

    }

    //Show current account balance
    function showBalance() public view returns(uint256)
    {
        return address(this).balance;
    }
}
