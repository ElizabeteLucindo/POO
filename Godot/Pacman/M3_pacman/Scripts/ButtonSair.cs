using Godot;
using System;

public partial class ButtonSair : Button
{
	private void Sair()
	{
		GetTree().Quit();
	}
}
