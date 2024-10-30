using Godot;
using System;

public partial class ButtonMenuGanhou : Button
{
	private void menu()
	{
		GetTree().ChangeSceneToFile("res://Cenas/menu.tscn");
	}
}
