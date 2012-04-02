{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 72.0, 67.0, 946.0, 771.0 ],
		"bglocked" : 0,
		"defrect" : [ 72.0, 67.0, 946.0, 771.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"metadata" : [  ],
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.op @op !- @val 255",
					"numoutlets" : 2,
					"outlettype" : [ "jit_matrix", "" ],
					"patching_rect" : [ 490.0, 165.0, 126.0, 20.0 ],
					"id" : "obj-16",
					"fontsize" : 11.595187,
					"numinlets" : 2,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "register services",
					"numoutlets" : 0,
					"patching_rect" : [ 322.0, 641.0, 122.0, 23.0 ],
					"id" : "obj-5",
					"fontsize" : 14.0,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "register \"uuu In\" 8888",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 78.0, 651.0, 126.0, 18.0 ],
					"id" : "obj-9",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "unregister",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 223.0, 651.0, 64.0, 18.0 ],
					"id" : "obj-10",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "mxj maw.net.bonjour video tcp",
					"numoutlets" : 4,
					"outlettype" : [ "list", "list", "list", "" ],
					"patching_rect" : [ 49.0, 694.0, 173.0, 20.0 ],
					"id" : "obj-11",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 35.0, 638.0, 404.0, 96.0 ],
					"id" : "obj-13",
					"bgcolor" : [ 0.917647, 0.937255, 0.670588, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "loadbang",
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 81.0, 500.0, 60.0, 20.0 ],
					"id" : "obj-2",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "register services",
					"numoutlets" : 0,
					"patching_rect" : [ 324.0, 536.0, 122.0, 23.0 ],
					"id" : "obj-44",
					"fontsize" : 14.0,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "register \"Video In\" 8888",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 80.0, 546.0, 136.0, 18.0 ],
					"id" : "obj-38",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "unregister",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 225.0, 546.0, 64.0, 18.0 ],
					"id" : "obj-35",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "mxj maw.net.bonjour video tcp",
					"numoutlets" : 4,
					"outlettype" : [ "list", "list", "list", "" ],
					"patching_rect" : [ 51.0, 589.0, 173.0, 20.0 ],
					"id" : "obj-31",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "panel",
					"numoutlets" : 0,
					"patching_rect" : [ 37.0, 533.0, 404.0, 96.0 ],
					"id" : "obj-42",
					"bgcolor" : [ 0.917647, 0.937255, 0.670588, 1.0 ],
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.dimmap @invert 0 1",
					"numoutlets" : 2,
					"outlettype" : [ "jit_matrix", "" ],
					"patching_rect" : [ 105.0, 147.0, 126.0, 20.0 ],
					"id" : "obj-8",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "Hgffjkhfddyutfg",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 38.0, 89.0, 179.0, 18.0 ],
					"id" : "obj-7",
					"fontsize" : 12.0,
					"numinlets" : 2,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "see accompanying openframeworks file to see what is up ...",
					"linecount" : 3,
					"numoutlets" : 0,
					"patching_rect" : [ 336.0, 32.0, 150.0, 48.0 ],
					"id" : "obj-6",
					"fontsize" : 12.0,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.fpsgui",
					"numoutlets" : 2,
					"mode" : 4,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 20.0, 268.333313, 80.0, 35.0 ],
					"id" : "obj-14",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.fpsgui",
					"numoutlets" : 2,
					"mode" : 3,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 20.0, 230.333313, 80.0, 35.0 ],
					"id" : "obj-12",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.fpsgui",
					"numoutlets" : 2,
					"mode" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 20.0, 192.333344, 80.0, 35.0 ],
					"id" : "obj-3",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 125.0, 65.0, 20.0, 20.0 ],
					"id" : "obj-1",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "print",
					"numoutlets" : 0,
					"patching_rect" : [ 305.0, 89.0, 33.0, 20.0 ],
					"id" : "obj-4",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.fpsgui",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 20.0, 154.0, 80.0, 35.0 ],
					"id" : "obj-21",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 230.0, 87.0, 20.0, 20.0 ],
					"id" : "obj-22",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "route connected",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 230.0, 64.0, 94.0, 20.0 ],
					"id" : "obj-23",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "jit.net.recv @port 8888",
					"numoutlets" : 3,
					"outlettype" : [ "jit_matrix", "", "" ],
					"patching_rect" : [ 20.0, 34.0, 229.0, 20.0 ],
					"id" : "obj-25",
					"fontsize" : 11.595187,
					"numinlets" : 1,
					"fontname" : "Arial"
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.pwindow",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 506.0, 230.0, 320.0, 240.0 ],
					"id" : "obj-15",
					"background" : 1,
					"numinlets" : 1,
					"presentation_rect" : [ 474.0, 238.0, 0.0, 0.0 ]
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "jit.pwindow",
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 105.0, 172.0, 320.0, 240.0 ],
					"id" : "obj-40",
					"background" : 1,
					"numinlets" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-16", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-16", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-8", 0 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [ 29.5, 132.0, 114.5, 132.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 1 ],
					"destination" : [ "obj-7", 1 ],
					"hidden" : 0,
					"midpoints" : [ 134.5, 60.0, 156.0, 60.0, 156.0, 78.0, 207.5, 78.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 2 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 1 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-25", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [ 29.5, 62.0, 29.5, 62.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-21", 0 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 0 ],
					"destination" : [ "obj-22", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-23", 1 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [ 89.5, 576.0, 60.5, 576.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [ 234.5, 574.0, 60.5, 574.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-2", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [ 232.5, 679.0, 58.5, 679.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [ 87.5, 681.0, 58.5, 681.0 ]
				}

			}
 ]
	}

}
