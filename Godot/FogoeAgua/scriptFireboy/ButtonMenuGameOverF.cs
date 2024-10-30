using Godot;
using System;

public partial class ButtonMenuGameOverF : Button
{
	
	private void menu_gameover_f()
	{
		GetTree().ChangeSceneToFile("res://cenasFireboy/menu_fireboy.tscn");
	}
}
