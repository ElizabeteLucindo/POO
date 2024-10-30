using Godot;
using System;

public partial class ButtonMenu : Button
{
	
	private void menu()
	{
		GetTree().ChangeSceneToFile("res://Cenas/menu.tscn");
	}
}


